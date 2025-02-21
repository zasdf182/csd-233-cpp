#include <iostream>
using namespace std;

char* str = "global";

void Print (char* str) {
    cout << str << '\n';
    {
        char* str = "local";
        cout << str << '\n';
        cout << "str" << '\n';
    }
}

int main (void) {
    Print("Parameter");
    return 0;
}
