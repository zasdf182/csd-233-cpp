#include "testLatin.hpp"
namespace TestLatin {


TEST(ToLowerTest, HandlesEmptyString) {
    char string1[] = {'\0'};
    char string2[] = {'\0'};
    ToLower(string2);
    EXPECT_STREQ(string1, string2);
}


TEST(ToLowerTest, HandlesAsciiPart1) {
    char string1[64 + 1] = {'\0'};
    char string2[64 + 1] = {'\0'};
    for (int i = 0; i < 64; i++) {
        string1[i] = static_cast<char>(i + 1);
        string2[i] = static_cast<char>(i + 1);
    } ToLower(string2);
    EXPECT_STREQ(string1, string2);
}


TEST(ToLowerTest, HandlesAsciiPart2) {
    char string1[96 - 91 + 1 + 1] = {'\0'};
    char string2[96 - 91 + 1 + 1] = {'\0'};
    for (int i = 0; i < 96 - 91 + 1; i++) {
        string1[i] = static_cast<char>(i + 91);
        string2[i] = static_cast<char>(i + 91);
    } ToLower(string2);
    EXPECT_STREQ(string1, string2);
}


TEST(ToLowerTest, HandlesAsciiPart3) {
    char string1[127 - 123 + 1 + 1] = {'\0'};
    char string2[127 - 123 + 1 + 1] = {'\0'};
    for (int i = 0; i < 127 - 123 + 1; i++) {
        string1[i] = static_cast<char>(i + 123);
        string2[i] = static_cast<char>(i + 123);
    } ToLower(string2);
    EXPECT_STREQ(string1, string2);
}


TEST(ToLowerTest, HandlesLowercase) {
    char string1[122 - 97 + 1 + 1] = {'\0'};
    char string2[122 - 97 + 1 + 1] = {'\0'};
    for (int i = 0; i < 122 - 97 + 1; i++) {
        string1[i] = static_cast<char>(i + 97);
        string2[i] = static_cast<char>(i + 97);
    } ToLower(string2);
    EXPECT_STREQ(string1, string2);
}


TEST(ToLowerTest, HandlesUppercase) {
    char string1[90 - 65 + 1 + 1] = {'\0'};
    char string2[90 - 65 + 1 + 1] = {'\0'};
    for (int i = 0; i < 122 - 97 + 1; i++) {
        string1[i] = static_cast<char>(i + 65);
        string2[i] = static_cast<char>(i + 65);
    } ToLower(string2);
    EXPECT_STRNE(string1, string2);
}


TEST(ToLowerTest, HandlesAllAscii) {
    char string1[127 + 1] = {'\0'};
    char string2[127 + 1] = {'\0'};
    for (int i = 0; i < 127; i++) {
        string1[i] = static_cast<char>(i + 1);
        string2[i] = static_cast<char>(i + 1);
    } ToLower(string2);
    EXPECT_STRNE(string1, string2);
}
}
