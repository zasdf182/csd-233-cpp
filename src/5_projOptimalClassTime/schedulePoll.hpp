#define daytypes 7
#define hourtypes 48
#define maxlinelen 4096
#define IMPORTBADFORMAT 'f'
#define IMPORTERROR 'x'
#define IMPORTGOOD '0'
#ifndef SCHEDULEPOLL_HPP
#define SCHEDULEPOLL_HPP




// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/** Defines all days of a week in the Gregorian calendar. */
enum day {sun, mon, tue, wed, thu, fri, sat, NUL};
static day getday(char const* charptr_);
static char const* getday(day dayenum_);




// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * A container for:
 *   -An hour of the day.
 *   -A char* array of students that prefer that hour.
 *   -Helper methods.
 */
class node {
    private:
        int __mem;
        void __alloc();
    protected:
        node* __next;
        float __hour;
        int __count;
        char const** __students;
    public:
        node(float hour_);
        ~node();
        node*& next() {return __next;}
        node* const& next() const {return __next;}
        float hour() {return __hour;}
        float hour() const {return __hour;}
        int count() {return __count;}
        int count() const {return __count;}
        char const* const* students() {return __students;}
        char const* const* students() const {return __students;}
        void add(char const* student_);
        void operator +=(char const* student_) {add(student_);}
};




// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * A container for all students' available hours for one day of the week.
 * Has a unique node for every hour of the day.
 * Each node has an array of student names.
 */
class linklist {
    protected:
        node* __head;
    public:
        linklist();
        ~linklist();
        node const* head() {return __head;}
        node const* head() const {return __head;}
        void add(float hour_, char const* student_);
};




// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * A container for all days of the week, and all students' available hours.
 * Has a unique linklist for every day of the week.
 * Each linklist has a unique node for every hour of the day.
 * Each node has an array of student names.
 */
class SchedulePoll {
    private:
        linklist** __days;
    public:
        SchedulePoll();
        ~SchedulePoll();
        int import(char const* schedulefile_);
        linklist const* const* days() {return __days;}
        linklist const* const* days() const {return __days;}
        linklist const& sun() {return *__days[::sun];}
        linklist const& mon() {return *__days[::mon];}
        linklist const& tue() {return *__days[::tue];}
        linklist const& wed() {return *__days[::wed];}
        linklist const& thu() {return *__days[::thu];}
        linklist const& fri() {return *__days[::fri];}
        linklist const& sat() {return *__days[::sat];}
        linklist const& sun() const {return *__days[::sun];}
        linklist const& mon() const {return *__days[::mon];}
        linklist const& tue() const {return *__days[::tue];}
        linklist const& wed() const {return *__days[::wed];}
        linklist const& thu() const {return *__days[::thu];}
        linklist const& fri() const {return *__days[::fri];}
        linklist const& sat() const {return *__days[::sat];}
        linklist const& operator +(int day_) {return *__days[day_];}
        linklist const& operator +(day day_) {return *__days[day_];}
        linklist const& operator [](int day_) {return *__days[day_];}
        linklist const& operator [](day day_) {return *__days[day_];}
        linklist const& operator +(int day_) const {return *__days[day_];}
        linklist const& operator +(day day_) const {return *__days[day_];}
        linklist const& operator [](int day_) const {return *__days[day_];}
        linklist const& operator [](day day_) const {return *__days[day_];}
        linklist const* begin() {return __days[0];}
        linklist const* begin() const {return __days[0];}
        linklist const* end() {return __days[6];}
        linklist const* end() const {return __days[6];}
};
#endif
