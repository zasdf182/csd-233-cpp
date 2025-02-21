#include <iostream>
using namespace std;

template<typename T>
T generic_add(T num1, T num2) {
    return num1 + num2;
}

int main() {
    int int1 = 1;
    int int2 = 2;
    cout << endl;
    cout << endl << "Generic Add <int>: " << int1 << " + " << int2;
    cout << endl << generic_add(int1, int2);

    double double1 = 1.1;
    double double2 = 2.2;
    cout << endl;
    cout << endl << "Generic Add <double>: " << double1 << " + " << double2;
    cout << endl << generic_add(double1, double2);

    string string1 = "1.1";
    string string2 = "2.2";
    cout << endl;
    cout << endl << "Generic Add <string>: " << string1 << " + " << string2;
    cout << endl << generic_add(string1, string2);

    cout << endl;
    cout << endl << "Hello World";
    cout << endl;
}