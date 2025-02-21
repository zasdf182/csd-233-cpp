#define NOTFOUND -1
#ifndef CHARP_HPP
#define CHARP_HPP
namespace word {

static const int find(char query_, char const* input_, int start_ = 0);
static const void trim(char* input_);
static const bool isnum(char const* str_);

}
#endif
