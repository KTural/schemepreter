#include "../include/procedure.hpp"
#include "../include/objects.hpp"
#include <gtest/gtest.h>

namespace {
    TEST(ObjectsTest, CheckGetExprType) {
        std::string sample = "x";
        Op op(sample);

        auto output = "variable";
        auto expected = op.get_expr_type();

        EXPECT_EQ(output, expected);

        std::vector<std::string> new_sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);

        Op new_op(proc);

        output = "procedure";
        expected = new_op.get_expr_type();
        EXPECT_EQ(output, expected);
    }

    TEST(ObjectsTest, CheckGetExprValue) {
        std::string sample = "x";
        Op op(sample);

        auto expected = op.get_expr_value();

        EXPECT_EQ(sample, expected);

        std::vector<std::string> new_sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);

        Op new_op(proc);

        auto output = "";
        expected = new_op.get_expr_value();
        EXPECT_EQ(output, expected);
    } 

    TEST(ObjectsTest, CheckGetProc) {
        std::vector<std::string> sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);

        Op op(proc);

        auto output = "3 ";
        auto expected = op.get_proc().get_proc_arg_list().to_string();
        EXPECT_EQ(output, expected);

        auto new_output = "( begin 2) ) ";
        auto new_expected = op.get_proc().get_proc_body().to_string();
        EXPECT_EQ(new_output, new_expected);
    }

    TEST(ObjectsTest, CheckNativeProc) {
        std::string sample = "x";
        Op op(sample);

        auto output = false;
        auto expected = op.check_native_procedure();

        EXPECT_EQ(output, expected);

        std::vector<std::string> new_sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);

        Op new_op(proc);

        expected = new_op.check_native_procedure();
        EXPECT_EQ(output, expected);
    }
}