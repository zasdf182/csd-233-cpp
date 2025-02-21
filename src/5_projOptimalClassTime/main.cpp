#include "schedulePoll.cpp"
#include "word.cpp"
#include "main.hpp"
#include <iostream>
#include <cctype>
#define secondchar 1
#define maxstrlen 4096
using namespace std;




int main(int argc, char** argv) {
    SchedulePoll* schedulepoll;
    intromsg();
    switch (getschedules(schedulepoll)) {
        case 'e':
            queryschedules(schedulepoll);
            break;
        case '0':
            quitprogram();
            break;
        default:
            cout << endl;
            cout << "ERROR: An unexpected error occurred. The program will now exit.";
            cout << endl;
            if (schedulepoll != nullptr) delete schedulepoll;
            return 1;
    } delete schedulepoll;
}




static void intromsg() {
    cout << endl;
    cout << endl << "Welcome to the Super Schedule Poll!";
    cout << endl << "This program has two parts.";
    cout << endl;
    cout << endl << "In Part 1, the program will prompt you for any number of text files to read.";
    cout << endl << "Each file contains a student's name and that student's preferred times to schedule classes.";
    cout << endl << "Files should follow this format:";
    cout << endl << "    - The file name follows this format: <first name of student>.txt";
    cout << endl << "    - Each line follows this format: <day>: <comma separated list of start times>";
    cout << endl << "    - <day> must be one of: sun, mon, tue, wed, thu, fri, sat.";
    cout << endl << "      If the student didnt want to attend class on a particular day, there wont be a line for that day.";
    cout << endl << "    - Times must be in military / 24 hour format with 30 minute granularity.";
    cout << endl << "      Use .5 to represent starting the class at 30 minutes after the hour.";
    cout << endl << "      For example 2:30pm would be represented with 14.5.";
    cout << endl << "    - Times do not have to be in sequential order.";
    cout << endl;
    cout << endl << "In Part 2, the user can query the program for times with a minimum number of matches.";
    cout << endl << "For example, a query of 2 will list all the times that have at least two students who prefer that time.";
    cout << endl;
}




static const char getschedules(SchedulePoll* out) {
    cout << endl;
    cout << endl << "<======== PART ONE ========>";
    cout << endl << "Enter one of these options:";
    cout << endl << "    - A file name to read";
    cout << endl << "    - \"e\" to finish reading schedules and proceed to Part 2";
    cout << endl << "    - \"0\" to quit the program";
    cout << endl;

    out = new SchedulePoll();
    char* userinput = new char[maxstrlen];

    while (true) {
        cout << endl;
        cout << endl << "--> ";
        cin >> userinput;

        switch (*userinput) {
            case 'e':
            case '0': {
                char char2 = userinput[secondchar];
                if (char2 == '\0' || isspace(char2))
                    return *userinput;
            } default:
                if (out->import(userinput) == IMPORTERROR)
                    cout << endl << "    ERROR: unable to read file " << userinput;
                else cout << endl << "    Successfully read file " << userinput;
        }
    } delete[] userinput;
}




static void queryschedules(SchedulePoll* in) {
    cout << endl;
    cout << endl << "<======== PART TWO ========>";
    cout << endl << "Enter one of these options:";
    cout << endl << "    - A number greater than 0. The program will list all times with at least that number of students.";
    cout << endl << "    - \"0\" to quit the program.";
    cout << endl;

    char* userinput = new char[maxstrlen];

    while (true) {
        cout << endl;
        cout << endl << "--> ";
        cin >> userinput;
        word::trim(userinput);

        if (*userinput == '0') {
            char char2 = userinput[secondchar];
            if (char2 == '\0' || isspace(char2)) {
                quitprogram();
                break;
            }
        }

        if (word::isnum(userinput)) {
            int num = atoi(userinput);
            for (int i = (day)::sun; i < daysinweek; i++) {
                // create iterator for schedulepoll::__days
            }
        } else
            cout << endl << "    ERROR: invalid input";
    } delete[] userinput;
}


static void quitprogram() {

}
