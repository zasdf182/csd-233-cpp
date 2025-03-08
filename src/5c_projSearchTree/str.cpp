#include "str.hpp"
using namespace std;
namespace Str {




////////////////////////////////////////////////////////////////////////////////
/// @brief Reads an entire file into a string.
/// Returns a string list of the file contents split at whitespaces.
/// Returns an empty list if file is empty or broken.
////////////////////////////////////////////////////////////////////////////////
static list<string> GetWordsFromFile(string filePath) {
    list<string> emptyList;
    ifstream file(filePath);
    if (!file.is_open() || !file.good()) return emptyList;
    return GetWordsFromFile(&file);
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Reads an entire file into a string.
/// Returns a string list of the file contents split at whitespaces.
/// Returns an empty list if file is empty or broken.
////////////////////////////////////////////////////////////////////////////////
static list<string> GetWordsFromFile(ifstream* file) {
    list<string> result;
    if (!file->is_open() || !file->good()) return result;

    // Read entire file contents into a string.
    ostringstream buffer;
    string fileContents;
    buffer << file->rdbuf();
    fileContents = buffer.str();

    // Split string at whitespaces.
    int substrStart = 0;
    int substrEnd = 0;
    int size = fileContents.size();

    // Find the start of the next split.
    while (substrStart < size) {
        if (isspace(fileContents.at(substrStart))) {
            substrStart++;
            continue;
        }

        // Find the end of the next split and insert substring into list.
        for (substrEnd = substrStart + 1; substrEnd < size; substrEnd++) {
            if (isspace(fileContents.at(substrEnd))) {
                int substrLength = substrEnd - substrStart;
                result.push_back(fileContents.substr(substrStart, substrLength));
                break;
            }
        }
        substrStart = substrEnd;
    } return result;
}




////////////////////////////////////////////////////////////////////////////////
/// @brief Trims leading and trailing whitespace from a string.
/// Mutates and returns the original input string.
////////////////////////////////////////////////////////////////////////////////
static string Trim(string input) {
    int substrStart = -1;
    int substrEnd = -1;

    // Find where leading whitespace ends.
    for (int i = 0; i < input.size(); i++) {
        if (!isspace(input.at(i))) {
            substrStart = i;
            break;
        }
    }

    // If leading whitespace doesnt end, its all whitespace, so clear the string.
    if (substrStart == -1) {
        input.clear();
        return input;
    }

    // Find where trailing whitespace begins.
    for (int i = input.size() - 1; i >= 0; i--) {
        if (!isspace(input.at(i))) {
            substrEnd = i;
            break;
        }
    }

    // Trim string.
    input.assign(input, substrStart, substrEnd - substrStart + 1);
    return input;
}
}
