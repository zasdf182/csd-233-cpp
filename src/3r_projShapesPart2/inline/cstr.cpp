#include "cstr.hpp"

////////////////////////////////////////////////////////////////////////////////
/// @brief Returns a new dynamic C string that is a clone of s.
///        Has undefined behavior if s does not have a terminating null char.
///        Remember to call delete[] later.
////////////////////////////////////////////////////////////////////////////////
inline char* Clone(char* s) {
    char* c = new char[std::strlen(s) + 1];
    *(c + std::strlen(s)) = '\0';
    Copy(s, c);
    return c;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Copies all chars from f to t.
///        Has undefined behavior if t does not have enough size to fit f.
///        Has undefined behavior if f does not have a terminating null char.
////////////////////////////////////////////////////////////////////////////////
inline void Copy(char* f, char* t) {
    for (int i = 0; i < std::strlen(f); i++)
        *(t + i) = *(f + i);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Mutates a C string.
///        Changes all uppercase Latin characters to lowercase.
///        Has undefined behavior if it does not have a terminating null char.
////////////////////////////////////////////////////////////////////////////////
inline void ToLower(char* input) {
    char* cursor = input;
    while (*cursor != '\0') {
        if (isalpha(*cursor))
            *cursor = tolower(*cursor);
        cursor++;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Checks if two C strings have the same contents.
////////////////////////////////////////////////////////////////////////////////
inline bool Equals(char* str1, char* str2) {
    if (strcmp(str1, str2) == 0) return true;
    else return false;
}
