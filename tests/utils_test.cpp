#include "../include/utils.hpp"
#include <gtest/gtest.h>

namespace {
    TEST(UtilsTest, CheckNumber) {
        std::string sample = "+ 2 4";
        auto expected = true;
        EXPECT_EQ(expected, number(sample));

        sample = "x";
        expected = false;
        EXPECT_EQ(expected, number(sample));

        sample = "#t";
        EXPECT_EQ(expected, number(sample));
    }

    TEST(UtilsTest, ParseInput) {
        std::string sample = "(\n+\n\n\n2\n(\n*\n3\n4\n)\n)";
        std::vector<std::string> expected =  {"(", "+", "2", "(", "*", "3", "4", ")", ")"};
        EXPECT_EQ(expected, parse_input(sample));

        sample = "(define\n\n(\nsquare\nx\n)\n(+\nx\n)\n\n)\n";
        expected = {"(", "define", "(", "square", "x", ")", "(", "+", "x", ")", ")"};
        EXPECT_EQ(expected, parse_input(sample));

        sample = "(\n(\nlambda\n ( x )  \n( + \nx x ) \n) \n4\n)  ";
        expected = {"(", "(", "lambda", "(", "x", ")", "(", "+", "x", "x", ")", ")", "4", ")"};
        EXPECT_EQ(expected, parse_input(sample));
    }
} 
