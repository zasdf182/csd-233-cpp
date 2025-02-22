#include "schedulePoll.cpp"
#include "word.cpp"
#include "main.hpp"
#include <iostream>
#include <cctype>
#include <cstdio>
#define secondchar 1
#define maxstrlen 4096
using namespace std;








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * A program with two parts.
 * The first part asks the user to input any number of text files with schedule data.
 * The second part lets the user query all times that have at least a certain number of matches.
 */
int main(int argc, char** argv) {
    SchedulePoll* programcontext = nullptr;
    engineptr engine = intromsg;

    while (engine != nullptr)
        switch (engine(programcontext)) {
            case ::intro:
                engine = intromsg;
                break;
            case ::part1:
                engine = getschedules;
                break;
            case ::part2:
                engine = queryschedules;
                break;
            case ::quit:
                quitprogram(programcontext);
                engine = nullptr;
                break;
            default:
                cout << endl << "ERROR: An unexpected error occurred." << endl;
                quitprogram(programcontext);
                return 1;
        }
}








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * Explains the program.
 */
static const enginegoto intromsg(SchedulePoll* ctx) {
    cout << endl;
    cout << endl << "Welcome to the Super Schedule Poll!";
    cout << endl << "This program has two parts.";
    cout << endl;
    cout << endl << "In Part 1, the program will prompt you for any number of text files to read.";
    cout << endl << "Each file contains a student's name and that student's preferred times to schedule classes.";
    cout << endl << "Files should follow this format:";
    cout << endl << "    - The file name follows this format: <first name of student>.txt";
    cout << endl << "    - Each line follows this format: <day>: <comma separated list of start times>";
    cout << endl << "    - <day> must be one of: sun, mon, tue, wed, thu, fri, sat";
    cout << endl << "      If the student didnt want to attend class on a particular day, there wont be a line for that day.";
    cout << endl << "    - Times must be in military / 24 hour format with 30 minute granularity.";
    cout << endl << "      Use .5 to represent starting the class at 30 minutes after the hour.";
    cout << endl << "      For example 2:30pm would be represented with 14.5";
    cout << endl << "    - Times do not have to be in sequential order.";
    cout << endl;
    cout << endl << "In Part 2, the user can query the program for times with a minimum number of matches.";
    cout << endl << "For example, a query of 2 will list all the times that have at least two students who prefer that time.";
    cout << endl;
    return ::part1;
}








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * Launches Part 1 of the program.
 * Loops and asks user to input any number of schedule files.
 * @returns -- 'e' if the user wants to continue to Part 2 of the program.
 *          -- '0' if the user wants to quit the program.
 */
static const enginegoto getschedules(SchedulePoll* out) {
    out = new SchedulePoll();
    cout << endl;
    cout << endl << "<======== PART ONE ========>";
    cout << endl << "Enter one of these options:";
    cout << endl << "    - A file name to read";
    cout << endl << "    - \"e\" to finish reading schedules and proceed to Part 2";
    cout << endl << "    - \"0\" to quit the program";
    cout << endl;

    char* userinput = new char[maxstrlen];
    char delimbuffer;

    while (true) {
        cout << endl;
        cout << endl << "--> ";
        cin >> userinput;
        word::trim(userinput);
        delimbuffer = userinput[secondchar];

        switch (*userinput) {
            case ::part2:
            case ::quit:
                if (delimbuffer == '\0' || isspace(delimbuffer)) {
                    delete[] userinput;
                    return (enginegoto) (*userinput);
                }
            default:
                if (out->import(userinput) == IMPORTERROR)
                    cout << "    ERROR: unable to read file " << userinput;
                else cout << "    Successfully read file " << userinput;
        }
    }
}








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * Launches Part 2 of the program.
 * Loops and asks the user to input a number.
 * Lists all the hours that have at least that number of preferring students.
 * @returns '0' if the user wants to quit the program.
 */
static const enginegoto queryschedules(SchedulePoll* in) {
    cout << endl;
    cout << endl << "<======== PART TWO ========>";
    cout << endl << "Enter one of these options:";
    cout << endl << "    - A number greater than 0. The program will list all times with at least that number of students.";
    cout << endl << "    - \"0\" to quit the program.";
    cout << endl;

    char* userinput = new char[maxstrlen];
    char delimbuffer;

    while (true) {
        cout << endl;
        cout << endl << "--> ";
        cin >> userinput;
        word::trim(userinput);
        delimbuffer = userinput[secondchar];

        if (*userinput == ::quit)
            if (delimbuffer == '\0' || isspace(delimbuffer)) {
                delete[] userinput;
                return ::quit;
            }

        if (!word::isint(userinput)) {
            cout << "    ERROR: invalid input";
            continue;
        }

        for (int i = ::sun; i < daytypes; i++) {
            int query = atoi(userinput);
            int matchcount = 0;
            char const* dayname = getday((day)i);
            node const** matches = new node const*[hourtypes];
            node const* nodeptr0 = nullptr;
            node const* nodeptr1 = in->days()[i]->head();

            while (nodeptr1 != nullptr) {
                if (nodeptr1->count() >= query)
                    matches[matchcount++] = nodeptr1;
                nodeptr0 = nodeptr1;
                nodeptr1 = nodeptr1->next();
            }

            for (int j = 0; j < matchcount; j++) {
                node const* match = matches[j];
                printf("%-3.3s at %-2.1f was chosen by %s", dayname, match->hour(), match->students()[0]);
                for (int k = 1; k < match->count(); k++)
                    cout << ", " << match->students()[k];
            }

            delete[] matches;
        }
    }
}








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //

/**
 * Collects garbage then quits the program.
 */
static void quitprogram(SchedulePoll* ctx) {
    if (ctx != nullptr) delete ctx;
    cout << "The program will now exit. Thank you and come again!";
    cout << endl << endl;
}
