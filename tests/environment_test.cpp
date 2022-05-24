#include "../include/environment.hpp"
#include <gtest/gtest.h>

namespace {
    TEST(EnvironmentTest, CheckGetSpecificElement) {
        std::vector<std::string> sample = {"(", "+", "2", "5", ")"};
        Env env(sample);

        size_t pos = 3;

        auto expected = "5";
        auto output = env.get_elem(pos);
        EXPECT_EQ(expected, output);
    }

    TEST(EnvironmentTest, CheckContentClearence) {
        std::vector<std::string> sample = {"(", "define", "(", "square", "x", ")", "(", "+", "x", ")", ")"};
        Env env(sample);

        env.clear_content_of_expr();

        std::vector<std::string> expected = {};
        EXPECT_EQ(expected, env.get_env());
    }

    TEST(EnvironmentTest, CheckConversionToString) {
        std::vector<std::string> sample = {"(", "(", "lambda", "(", "x", ")", "(", "+", "x", "x", ")", ")", "4", ")"};
        Env env(sample);

        std::string expected = "( ( lambda ( x ) ( + x x ) ) 4 ) ";

        EXPECT_EQ(expected, env.to_string());
    }

    TEST(EnvironmentTest, CheckNumberOfExpressions) {
        std::vector<std::string> sample = {"(", "+", "2", "(", "*", "2", "(", "/", "9", "3", ")", ")",")"};
        Env env(sample);

        size_t expected = 3;
        EXPECT_EQ(expected, env.get_num_exprs());

        sample = {"(", "begin", "(", "set!", "x", "5", ")", "(", "+", "x", "1", ")", ")"};
        EXPECT_EQ(expected, env.get_num_exprs());
    }

    TEST(EnvironmentTest, CheckEnvSize) {
        std::vector<std::string> sample = {"(", "define", "(", "square", "x", ")", "(", "*", "x", "(", "+", "2", "x", ")", ")"};
        Env env(sample);

        size_t expected = 15;
        EXPECT_EQ(expected, env.get_full_size());

        sample = {};
        Env env2(sample);

        expected = 0;
        EXPECT_EQ(expected, env2.get_full_size());
    }

    TEST(EnvironmentTest, CheckGetMember) {
        std::vector<std::string> sample = {"(", "define", "(", "square", "x", ")", "(", "*", "x", "(", "+", "2", "x", ")", ")"};
        Env env(sample);

        size_t pos = 1;

        auto new_env = env.get_member(pos);
        auto output = new_env.to_string();

        auto expected = "( square x ) ";
        EXPECT_EQ(expected, output);
    }
}