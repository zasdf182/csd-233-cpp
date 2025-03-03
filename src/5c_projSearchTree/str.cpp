using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "str.hpp"
namespace Str {




////////////////////////////////////////////////////////////////////////////////
/// Reads an entire file into a string.
/// Returns a string list of the file contents split at whitespaces.
////////////////////////////////////////////////////////////////////////////////
// static list<string> GetWordsFromFile(string filepath) {
// list<string> result = list<string>();

// // Open file. Return empty list if file is empty or broken.
// std::ifstream file(filepath);
// if (!file.is_open() || !file.good()) return result;
// }




////////////////////////////////////////////////////////////////////////////////
/// Trims leading and trailing whitespace from a string.
/// Mutates and returns the original input string.
////////////////////////////////////////////////////////////////////////////////
static string Trim(string input) {
    int substringStart = -1;
    int substringEnd = -1;

    // Find where leading whitespace ends.
    for (int i = 0; i < input.size(); i++) {
        if (!isspace(input.at(i))) {
            substringStart = i;
            break;
        }
    }

    // If leading whitespace doesnt end, its all whitespace, so clear the string.
    if (substringStart == -1) {
        input.clear();
        return input;
    }

    // Find where trailing whitespace begins.
    for (int i = input.size() - 1; i >= 0; i--) {
        if (!isspace(input.at(i))) {
            substringEnd = i;
            break;
        }
    }

    // Trim string.
    input.assign(input, substringStart, substringEnd - substringStart + 1);
    return input;
}
}
