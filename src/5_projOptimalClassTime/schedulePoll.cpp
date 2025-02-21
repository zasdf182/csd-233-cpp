#include "schedulePoll.hpp"
#include "word.hpp"
#include <cstring>
#include <algorithm>
#include <fstream>




// ====================================================== //
// ================== DAYS OF THE WEEK ================== //
// ====================================================== //

static day getday(char const* charptr) {
    if (strcmp(charptr, "sun") == 0) return (day)::sun;
    else if (strcmp(charptr, "mon") == 0) return (day)::mon;
    else if (strcmp(charptr, "tue") == 0) return (day)::tue;
    else if (strcmp(charptr, "wed") == 0) return (day)::wed;
    else if (strcmp(charptr, "thu") == 0) return (day)::thu;
    else if (strcmp(charptr, "fri") == 0) return (day)::fri;
    else if (strcmp(charptr, "sat") == 0) return (day)::sat;
    else return (day)::NUL;
}




// ====================================================== //
// ========= LINKED LIST FOR ONE DAY OF THE WEEK ======== //
// ======== OF STUDENTS AND THEIR AVAILABLE HOURS ======= //
// ====================================================== //

linklist::linklist() {
    __head = nullptr;
};

linklist::~linklist() {
    node* ptr0 = nullptr;
    node* ptr1 = __head;
    while (ptr1 != nullptr) {
        ptr0 = ptr1;
        ptr1 = ptr1->next;
        delete ptr0;
    }
};




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/** IF NODE WITH SAME HOUR EXISTS ADD TO IT - IF NOT CREATE NEW ONE */

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
            newnode->next = ptr1;
            if (ptr0 != nullptr)
                ptr0->next = newnode;
            else
                __head = newnode;
            return;
        }

        // INCREMENT LOOP COUNTER
        ptr0 = ptr1;
        ptr1 = ptr1->next;
    } while (ptr1->next != nullptr);

    // LAST NODE IS SMALLER - CREATE NODE AT END OF LIST
    node* newnode = new node(hour_);
    newnode->add(student_);
    ptr1->next = newnode;
};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

node::node(float hour_) {
    __mem = 4;
    __hour = hour_;
    __count = 0;
    __students = new char const*[__mem];
    next = nullptr;
}

node::~node() {
    delete[] __students;
}

void node::add(char const* student_) {
    if (__count == __mem) __alloc();
    __students[__count++] = student_;
}

void node::__alloc() {
    char const** newptr = new char const*[__mem * __mem];
    std::copy(__students, (__students + __mem), newptr);
    for (int i = 0; i < __mem; i++)
        delete[] __students[i];
    delete[] __students;
    __students = newptr;
    __mem = __mem * __mem;
}




// ====================================================== //
// ========= CONTAINER FOR ALL DAYS OF THE WEEK ========= //
// ========== AND ALL STUDENTS AVAILABLE HOURS ========== //
// ====================================================== //

SchedulePoll::SchedulePoll() {
    __days = new linklist[daysinweek];
    *(__days + (day)::sun) = linklist();
    *(__days + (day)::mon) = linklist();
    *(__days + (day)::tue) = linklist();
    *(__days + (day)::wed) = linklist();
    *(__days + (day)::thu) = linklist();
    *(__days + (day)::fri) = linklist();
    *(__days + (day)::sat) = linklist();
}

SchedulePoll::~SchedulePoll() {
    delete[] __days;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/** READ TEXT FILE WITH STUDENT SCHEDULE */

int SchedulePoll::import(char const* schedulefile_) {
    int maxlinelen = 4096;
    int maxhourtypes = 48;
    std::ifstream file(schedulefile_);
    if (!file.is_open() || !file.good()) return IMPORTERROR;

    // FILE NAME IS STUDENT NAME - REMOVE FILE EXTENSION
    char* student;
    int studentlen = word::find('.', schedulefile_);
    if (studentlen == NOTFOUND)
        studentlen = std::strlen(schedulefile_);
    student = new char[studentlen + 1];
    student[studentlen] = '\0';
    std::copy(schedulefile_, (schedulefile_ + studentlen), student);

    // EACH LINE HAS ONE DAY AND MULTIPLE HOURS
    char* line = new char[maxlinelen];
    while (file.good()) {
        file.getline(line, maxlinelen);
        word::trim(line);

        // DAY IS BEFORE COLON
        char* jour;
        int colonpos = word::find(':', line);
        if (colonpos == NOTFOUND)
            throw std::runtime_error("ERROR: Incorrect schedule format");
        jour = new char[colonpos + 1];
        jour[colonpos] = '\0';
        std::copy(line, (line + colonpos), jour);
        word::trim(jour);

        // HOURS ARE SEPARATED BY COMMAS
        char** hours = new char*[maxhourtypes];
        int hourcount = 0;

        int hourpos = colonpos + 1;
        int hourend = word::find(',', line, hourpos);
        while (hourend != NOTFOUND) {
            char** hourptr = hours + hourcount++;
            *hourptr = new char[(hourend - hourpos) + 1];
            *hourptr[hourend - hourpos] = '\0';
            std::copy((line + hourpos), (line + hourend), *hourptr);
            word::trim(*hourptr);

            hourpos = hourend + 1;
            hourend = word::find(',', line, hourpos);
        }

        // EVERY HOUR HAS A COLON AFTER IT - EXCEPT THE LAST HOUR
        char** hourptr = hours + hourcount++;
        *hourptr = new char[(hourend - hourpos) + 1];
        *hourptr[hourend - hourpos] = '\0';
        std::copy((line + hourpos), (line + hourend), *hourptr);
        word::trim(*hourptr);

        // ADD DATA TO LINKED LIST
        for (int i = 0; i < hourcount; i++)
            __days[getday(jour)].add(std::atof(hours[i]), student);

        // GARBAGE COLLECTION
        delete[] jour;
        for (int i = 0; i < maxhourtypes; i++)
            delete[] hours[i];
        delete[] hours;
    }

    // GARBAGE COLLECTION
    delete[] student;
    delete[] line;
    file.close();
    return IMPORTGOOD;
}
