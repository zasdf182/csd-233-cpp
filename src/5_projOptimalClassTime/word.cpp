#include "word.hpp"
#include <cstring>
#include <cctype>
namespace word {

static const int find(char query_, char const* input_, int start_) {
    if (input_ == nullptr) return NOTFOUND;
    if (start_ >= std::strlen(input_)) return NOTFOUND;
    char const* scanner = input_;
    int charpos = start_;
    while (scanner[charpos] != '\0')
        if (scanner[charpos++] == query_)
            return charpos;
    return NOTFOUND;
}

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

static const bool isnum(char const* str_) {
    if (str_ == nullptr) return false;
    if (*str_ == '\0') return false;
    char const* ptr = str_;
    while (*ptr != '\0') {
        if (!std::isdigit(*ptr))
            if (*ptr != '.')
                return false;
        ptr++;
    } return true;
}
}
