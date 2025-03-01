#include <iostream>
#include "calc.cpp"
using namespace std;

int main() {
    // Numbers used to test calculator
    int num1 = 42;
    int num2 = 8;

    // Calculator operations
    IntOperation* adder = new Add(num1, num2);
    IntOperation* subtracter = new Subtract(num1, num2);
    IntOperation* multiplier = new Multiply(num1, num2);
    IntOperation* divider = new Divide(num1, num2);

    // Calculation results
    int addition = adder->calc();
    int subtraction = subtracter->calc();
    int multiplication = multiplier->calc();
    int division = divider->calc();

    // Output results
    cout << endl;
    cout << endl << "===============";

    adder->print();
    subtracter->print();
    multiplier->print();
    divider->print();

    cout << endl << "===============";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    // Collect garbage
    delete adder;
    delete subtracter;
    delete multiplier;
    delete divider;
}
