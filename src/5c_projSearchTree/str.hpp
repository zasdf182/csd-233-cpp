#ifndef STR_HPP
#define STR_HPP
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
namespace Str {

////////////////////////////////////////////////////////////////////////////////
/// @brief Reads an entire file into a string.
/// Returns a string list of the file contents split at whitespaces.
/// Returns an empty list if file is empty or broken.
////////////////////////////////////////////////////////////////////////////////
static list<string> GetWordsFromFile(string filePath);

////////////////////////////////////////////////////////////////////////////////
/// @brief Reads an entire file into a string.
/// Returns a string list of the file contents split at whitespaces.
/// Returns an empty list if file is empty or broken.
////////////////////////////////////////////////////////////////////////////////
static list<string> GetWordsFromFile(ifstream* file);

////////////////////////////////////////////////////////////////////////////////
/// @brief Trims leading and trailing whitespace from a string.
/// Mutates and returns the original input string.
////////////////////////////////////////////////////////////////////////////////
static string Trim(string input);

}
#endif
