#ifndef CALC_HPP
#define CALC_HPP




// ##################################################################### //
/** A container for a single calculator operation. */
struct IntOperation {
    protected:
        int input1;
        int input2;
        char sign;
    public:
        IntOperation(int a, int b, char op) : input1(a), input2(b), sign(op) {}
        virtual int calc();
        void print();
};




// ##################################################################### //
/** A single calculator addition operation. */
struct Add : public IntOperation {
    Add(int a, int b) : IntOperation(a, b, '+') {}
    virtual int calc();
};

/** A single calculator subtraction operation. */
struct Subtract : public IntOperation {
    Subtract(int a, int b) : IntOperation(a, b, '-') {}
    virtual int calc();
};

/** A single calculator multiplication operation. */
struct Multiply : public IntOperation {
    Multiply(int a, int b) : IntOperation(a, b, '*') {}
    virtual int calc();
};

/** A single calculator division operation. */
struct Divide : public IntOperation {
    Divide(int a, int b) : IntOperation(a, b, '/') {}
    virtual int calc();
};




// ##################################################################### //
#endif
