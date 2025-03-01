#include <iostream>
#include "calc.hpp"
using namespace std;

/** Get the result of the calculator operation. */
int IntOperation::calc() {return 0;}

/** Print a formatted string to standard output, detailing the calculation. */
void IntOperation::print() {
    printf("\n%2i %c %-2i == %4i", input1, sign, input2, calc());
}

/** Get the result of the calculator operation. */
int Add::calc() {return input1 + input2;}

/** Get the result of the calculator operation. */
int Subtract::calc() {return input1 - input2;}

/** Get the result of the calculator operation. */
int Multiply::calc() {return input1 * input2;}

/** Get the result of the calculator operation. */
int Divide::calc() {return input1 / input2;}
