#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << endl;
    cout << "Greetings! This program outputs argv." << endl;
    cout << "Executable name is " << argv[0] << endl;

    if (argc > 1)
        for (int i = 1; i < argc; i++)
            cout << "arg" << i << " is: " << argv[i] << endl;
    else
        cout << "No args were passed to the program." << endl;

    cout << endl;
}
