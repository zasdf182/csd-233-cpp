#include "str.cpp"

int main() {
    std::list<std::string> newlist = Str::GetWordsFromFile("build/wordlist.txt");
    return 0;
}
