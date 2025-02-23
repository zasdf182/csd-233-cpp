#include "word.hpp"
#include <cstring>
#include <cctype>








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //
namespace word {

/**
 * Trims leading whitespace.
 * Then finds the first whitespace character and trims everything after that.
 * That means, if a line is input, it will be trimmed to the first word.
 * Mutates the original c-style string.
 */
static const void trim(char* input_) {
    if (input_ == nullptr) return;
    if (*input_ == '\0') return;
    char* ptr = input_;
    int i = 0;
    while (std::isspace(*ptr)) ptr++;
    while (!std::isspace(*ptr)) {
        if (*ptr == '\0') break;
        input_[i++] = *ptr++;
    } input_[i] = '\0';
}

/**
 * Checks if there are any non-numeric characters in a c-style string.
 */
static const bool isint(char const* str_) {
    if (str_ == nullptr) return false;
    if (*str_ == '\0') return false;
    char const* ptr = str_;
    while (*ptr != '\0')
        if (!std::isdigit(*ptr++))
            return false;
    return true;
}
}








// ##################################################################### //
// ##################################################################### //
// ##################################################################### //
namespace line {

/**
 * Finds the first occurrence of a char in a c-style array.
 * @returns Array index or NOTFOUND (-1).
 */
static const int find(char query_, char const* input_, int start_) {
    if (input_ == nullptr) return NOTFOUND;
    if (start_ < 0) start_ = 0;
    if (start_ >= std::strlen(input_)) return NOTFOUND;
    char const* scanner = input_;
    int charpos = start_;
    while (scanner[charpos] != '\0')
        if (scanner[charpos] == query_)
            return charpos;
        else charpos++;
    return NOTFOUND;
}

/**
 * Finds the last occurrence of a char in a c-style array.
 * @returns Array index or NOTFOUND (-1).
 */
static const int findlast(char query_, char const* input_, int start_) {
    int pos = NOTFOUND;
    int scanner = find(query_, input_, start_);
    while (scanner != NOTFOUND) {
        pos = scanner;
        scanner = find(query_, input_, pos + 1);
    } return pos;
}
}
