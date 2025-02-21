#define daysinweek 7
#define IMPORTERROR 42
#define IMPORTGOOD 0
#ifndef SCHEDULEPOLL_HPP
#define SCHEDULEPOLL_HPP




// ====================================================== //
// ================== DAYS OF THE WEEK ================== //
// ====================================================== //

enum day {sun, mon, tue, wed, thu, fri, sat, NUL};
static day getday(char const* charptr);




// ====================================================== //
// ========= LINKED LIST FOR ONE DAY OF THE WEEK ======== //
// ======== OF STUDENTS AND THEIR AVAILABLE HOURS ======= //
// ====================================================== //

class node {
    private:
        int __mem;
        void __alloc();
    protected:
        float __hour;
        int __count;
        char const** __students;
    public:
        node(float hour_);
        ~node();
        node* next;
        float hour() {return __hour;}
        int count() {return __count;}
        char const* const* students() {return __students;}
        void add(char const* student_);
        void operator +=(char const* student_) {add(student_);}
};

class linklist {
    protected:
        node* __head;
    public:
        linklist();
        ~linklist();
        node const* head() {return __head;}
        node const* at(float hour_);
        node const* operator +(float hour_) {return at(hour_);}
        node const* operator [](float hour_) {return at(hour_);}
        void add(float hour_, char const* student_);
};




// ====================================================== //
// ========= CONTAINER FOR ALL DAYS OF THE WEEK ========= //
// ========== AND ALL STUDENTS AVAILABLE HOURS ========== //
// ====================================================== //

class SchedulePoll {
    private:
        linklist* __days;
    public:
        SchedulePoll();
        ~SchedulePoll();
        int import(char const* schedulefile_);
        linklist const* days() {return __days;}
        linklist const& sun() {return *(__days + (day)::sun);}
        linklist const& mon() {return *(__days + (day)::mon);}
        linklist const& tue() {return *(__days + (day)::tue);}
        linklist const& wed() {return *(__days + (day)::wed);}
        linklist const& thu() {return *(__days + (day)::thu);}
        linklist const& fri() {return *(__days + (day)::fri);}
        linklist const& sat() {return *(__days + (day)::sat);}
        linklist const& operator +(day day_) {return __days[day_];}
        linklist const& operator [](day day_) {return __days[day_];}
};
#endif
