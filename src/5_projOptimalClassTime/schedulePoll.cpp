#include "schedulePoll.hpp"
#include "word.hpp"
#include <cstring>
#include <algorithm>
#include <fstream>
#include <filesystem>
















// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/** Parses a c-style string and returns an enum. */
static day getday(char const* charptr_) {
    if (strcmp(charptr_, "sun") == 0) return ::sun;
    else if (strcmp(charptr_, "mon") == 0) return ::mon;
    else if (strcmp(charptr_, "tue") == 0) return ::tue;
    else if (strcmp(charptr_, "wed") == 0) return ::wed;
    else if (strcmp(charptr_, "thu") == 0) return ::thu;
    else if (strcmp(charptr_, "fri") == 0) return ::fri;
    else if (strcmp(charptr_, "sat") == 0) return ::sat;
    else return ::NUL;
}

/** Parses an enum and returns a c-style string. */
static char const* getday(day day_) {
    if (day_ == ::sun) return "sun";
    else if (day_ == ::mon) return "mon";
    else if (day_ == ::tue) return "tue";
    else if (day_ == ::wed) return "wed";
    else if (day_ == ::thu) return "thu";
    else if (day_ == ::fri) return "fri";
    else if (day_ == ::sat) return "sat";
    else return nullptr;
}















// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/** Constructor that inits private defaults and allocates memory. */
node::node(float hour_) {
    __mem = 4;
    __hour = hour_;
    __count = 0;
    __students = new char const*[__mem];
    __next = nullptr;
}

/** Destructor that collects garbage. */
node::~node() {
    for (int i = 0; i < __count; i++)
        delete[] __students[i];
    delete[] __students;
}

/**
 * Tells the node that a student prefers this node's hour.
 * It will add the student name to an internal array, and update helper methods.
 */
void node::add(char const* student_) {
    int len = std::strlen(student_);
    char* name = new char[len + 1];
    name[len] = '\0';
    if (__count == __mem) __alloc();
    std::copy(student_, (student_ + len), name);
    __students[__count++] = name;
}

/**
 * Private helper method that allocates more memory when the node fills up.
 */
void node::__alloc() {
    char const** newptr = new char const*[__mem * __mem];
    std::copy(__students, (__students + __mem), newptr);
    for (int i = 0; i < __mem; i++)
        delete[] __students[i];
    delete[] __students;
    __students = newptr;
    __mem = __mem * __mem;
}
















// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/** Constructor that inits private defaults. */
linklist::linklist() {
    __head = nullptr;
};

/** Constructor that collects garbage. */
linklist::~linklist() {
    node* ptr0 = nullptr;
    node* ptr1 = __head;
    while (ptr1 != nullptr) {
        ptr0 = ptr1;
        ptr1 = ptr1->next();
        delete ptr0;
    }
};

/**
 * Tells the linklist that a student prefers a specific hour of the day.
 * The linklist has a unique node for each hour of the day.
 * Each node starts as null, and is created when that hour is first requested.
 * Each node has an array that tracks all the students that prefer that hour.
 */
void linklist::add(float hour_, char const* student_) {
    if (__head == nullptr) {
        __head = new node(hour_);
        __head->add(student_);
        return;
    }

    // IF LIST NOT EMPTY - FIND EXISTING NODE - OR SPOT TO CREATE NEW NODE
    node* ptr0 = nullptr;
    node* ptr1 = __head;
    do {

        // EXISTING NODE FOUND - ADD TO IT
        if (ptr1->hour() == hour_) {
            ptr1->add(student_);
            return;
        }

        // GREATER NODE FOUND - CREATE NEW NODE BEFORE IT
        else if (ptr1->hour() > hour_) {
            node* newnode = new node(hour_);
            newnode->add(student_);
            newnode->next() = ptr1;
            if (ptr0 != nullptr)
                ptr0->next() = newnode;
            else
                __head = newnode;
            return;
        }

        // INCREMENT LOOP COUNTER
        ptr0 = ptr1;
        ptr1 = ptr1->next();
    } while (ptr1 != nullptr);

    // LAST NODE IS SMALLER - CREATE NODE AT END OF LIST
    node* newnode = new node(hour_);
    newnode->add(student_);
    ptr0->next() = newnode;
};
















// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**Constructor that inits private objects. */
SchedulePoll::SchedulePoll() {
    __days = new linklist*[daytypes];
    __days[::sun] = new linklist();
    __days[::mon] = new linklist();
    __days[::tue] = new linklist();
    __days[::wed] = new linklist();
    __days[::thu] = new linklist();
    __days[::fri] = new linklist();
    __days[::sat] = new linklist();
}

/** Destructor that deallocates memory. */
SchedulePoll::~SchedulePoll() {
    for (int i = 0; i < daytypes; i++)
        delete __days[i];
    delete[] __days;
}

/**
 * Reads a text file filled with students' preferred hours.
 * Files should follow this format:
 *   -- The file name follows this format: <first name of student>.txt
 *   -- Each line follows this format: <day>: <comma separated list of start times>
 *   -- <day> must be one of: sun, mon, tue, wed, thu, fri, sat
 *   -- Times must be in military / 24 hour format with 30 minute granularity.
 *        Use .5 to represent starting the class at 30 minutes after the hour.
 *        For example 2:30pm would be represented with 14.5
 *   -- Times do not have to be in sequential order.
 */
int SchedulePoll::import(char const* schedulefile_) {
    std::ifstream file(schedulefile_);
    if (!file.is_open() || !file.good()) return IMPORTERROR;

    // FILE NAME IS STUDENT NAME - REMOVE FILE PATH AND FILE EXTENSION
    int studentpos = line::findlast('/', schedulefile_);
    if (studentpos == NOTFOUND)
        studentpos = line::findlast('\\', schedulefile_);
    if (studentpos == NOTFOUND)
        studentpos = 0;
    else studentpos++;

    int studentend = line::findlast('.', schedulefile_);
    if (studentend == NOTFOUND)
        studentend = std::strlen(schedulefile_);

    char* student = new char[1 + studentend - studentpos];
    student[studentend - studentpos] = '\0';
    std::copy((schedulefile_ + studentpos), (schedulefile_ + studentend), student);

    // EACH LINE HAS ONE DAY AND MULTIPLE HOURS
    char* line = new char[maxlinelen];
    while (file.good()) {
        file.getline(line, maxlinelen);
        line::trim(line);

        // IGNORE EMPTY LINES
        if (*line == '\0') continue;

        // DAY IS BEFORE COLON
        char* jour;
        int colonpos = line::find(':', line);
        if (colonpos == NOTFOUND)
            return IMPORTBADFORMAT;
        jour = new char[colonpos + 1];
        jour[colonpos] = '\0';
        std::copy(line, (line + colonpos), jour);
        word::trim(jour);

        // HOURS ARE SEPARATED BY COMMAS
        char** hours = new char*[hourtypes];
        int hourcount = 0;
        int hourpos = colonpos + 1;
        int hourend = line::find(',', line, hourpos);

        while (hourend != NOTFOUND) {
            char** hourptr = hours + hourcount++;
            *hourptr = new char[(hourend - hourpos) + 1];
            (*hourptr)[hourend - hourpos] = '\0';
            std::copy((line + hourpos), (line + hourend), *hourptr);
            word::trim(*hourptr);

            hourpos = hourend + 1;
            hourend = line::find(',', line, hourpos);
        }

        // EVERY HOUR HAS A COMMA AFTER IT - EXCEPT THE LAST HOUR
        char** hourptr = hours + hourcount++;
        hourend = std::strlen(line);
        *hourptr = new char[(hourend - hourpos) + 1];
        (*hourptr)[hourend - hourpos] = '\0';
        std::copy((line + hourpos), (line + hourend), *hourptr);
        word::trim(*hourptr);

        // ADD DATA TO LINKED LIST
        for (int i = 0; i < hourcount; i++)
            __days[getday(jour)]->add(std::atof(hours[i]), student);

        // GARBAGE COLLECTION
        delete[] jour;
        for (int i = 0; i < hourcount; i++)
            delete[] hours[i];
        delete[] hours;
    }

    // GARBAGE COLLECTION
    delete[] student;
    delete[] line;
    file.close();
    return IMPORTGOOD;
}
