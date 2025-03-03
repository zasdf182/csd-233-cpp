#include <string>
#include <gtest/gtest.h>
#include "str.cpp"
namespace TestStr {

//============================================================================//
// Unit tests for Str::Trim()
//============================================================================//
TEST(TrimTest, HandlesEmptyString) {
    EXPECT_EQ(Str::Trim(""), "");
}

TEST(TrimTest, HandlesOnlySpaces) {
    EXPECT_EQ(Str::Trim(" "), "");
    EXPECT_EQ(Str::Trim("  "), "");
    EXPECT_EQ(Str::Trim("                     "), "");
    EXPECT_EQ(Str::Trim("\f"), "");
    EXPECT_EQ(Str::Trim("\f\f"), "");
    EXPECT_EQ(Str::Trim("\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f"), "");
    EXPECT_EQ(Str::Trim("\n"), "");
    EXPECT_EQ(Str::Trim("\n\n"), "");
    EXPECT_EQ(Str::Trim("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"), "");
    EXPECT_EQ(Str::Trim("\r"), "");
    EXPECT_EQ(Str::Trim("\r\r"), "");
    EXPECT_EQ(Str::Trim("\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r"), "");
    EXPECT_EQ(Str::Trim("\t"), "");
    EXPECT_EQ(Str::Trim("\t\t"), "");
    EXPECT_EQ(Str::Trim("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"), "");
    EXPECT_EQ(Str::Trim("\v"), "");
    EXPECT_EQ(Str::Trim("\v\v"), "");
    EXPECT_EQ(Str::Trim("\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v"), "");
}

TEST(TrimTest, HandlesLeadingSpaces) {
    EXPECT_EQ(Str::Trim(" a"), "a");
    EXPECT_EQ(Str::Trim("  bc"), "bc");
    EXPECT_EQ(Str::Trim("                       defghijklmnopqrstuvwxyz"), "defghijklmnopqrstuvwxyz");
}

TEST(TrimTest, HandlesTrailingSpaces) {
    EXPECT_EQ(Str::Trim("a "), "a");
    EXPECT_EQ(Str::Trim("bc  "), "bc");
    EXPECT_EQ(Str::Trim("defghijklmnopqrstuvwxyz                       "), "defghijklmnopqrstuvwxyz");
}

TEST(TrimTest, HandlesLeadingAndTrailingSpaces) {
    EXPECT_EQ(Str::Trim(" a "), "a");
    EXPECT_EQ(Str::Trim("  bc  "), "bc");
    EXPECT_EQ(Str::Trim("                       defghijklmnopqrstuvwxyz                       "), "defghijklmnopqrstuvwxyz");
}

TEST(TrimTest, HandlesMiddleSpaces) {
    EXPECT_EQ(Str::Trim("a a"), "a a");
    EXPECT_EQ(Str::Trim(" b b "), "b b");
    EXPECT_EQ(Str::Trim("  cc  cc  "), "cc  cc");
    EXPECT_EQ(Str::Trim("         ddddddddd         ddddddddd         "), "ddddddddd         ddddddddd");
}
}
