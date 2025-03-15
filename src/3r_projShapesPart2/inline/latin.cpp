#include "latin.hpp"

////////////////////////////////////////////////////////////////////////////////
/// @brief Mutates a string. Assumes a valid string with terminating null char.
///        Changes all uppercase Latin characters to lowercase.
////////////////////////////////////////////////////////////////////////////////
inline void ToLower(char* input) {
    char* cursor = input;
    while (*cursor != '\0') {
        if (isalpha(*cursor))
            *cursor = tolower(*cursor);
        cursor++;
    }
}
