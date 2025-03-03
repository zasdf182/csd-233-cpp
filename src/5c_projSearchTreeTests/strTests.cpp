#include <string>
#include <gtest/gtest.h>
#include "str.cpp"
namespace StrTests {
void main() {}

////////////////////////////////////////////////////////////////////////////////
/// Runs all unit tests for Str::Str::Trim().
////////////////////////////////////////////////////////////////////////////////
TEST(StrTestSuite, Trim) {
    EXPECT_EQ(Str::Trim(""), "");
    EXPECT_EQ(Str::Trim("    "), "");
    EXPECT_EQ(Str::Trim("    abcd"), "abcd");
    EXPECT_EQ(Str::Trim("abcd    "), "abcd");
    EXPECT_EQ(Str::Trim("    abcd    "), "abcd");
    EXPECT_EQ(Str::Trim(" \f \n \r \t \v abcd \f \n \r \t \v "), "abcd");
}
}
