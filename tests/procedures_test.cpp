#include "../include/procedure.hpp"
#include <gtest/gtest.h>

namespace {
    inline std::string trim(std::string& str) {
        str.erase(str.find_last_not_of(' ') + 1);         
        str.erase(0, str.find_first_not_of(' '));   
        return str;
    }

    TEST(ProcedureTest, CheckGetArgList) {
        std::vector<std::string> sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        std::string output = "3";

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);
        std::string expected = proc.get_proc_arg_list().to_string();
        expected = trim(expected);

        EXPECT_EQ(output, expected);

        sample = {"(", "(", "lambda", "x", "x", ")", "3", "4", "5", "6", ")" };
        Env new_env(sample);

        pos = 1;
        arg = new_env.get_member(pos);
        Procedure new_proc(arg);
        std::string new_expected = new_proc.get_proc_arg_list().to_string();
        new_expected = trim(new_expected);

        EXPECT_EQ(output, new_expected);         
    }

    TEST(ProcedureTest, CheckGetProcBody) {
        std::vector<std::string> sample = {"(", "+", "2", "(", "*", "3", "2" ")", ")"};
        Env env(sample);

        std::string output = "( begin 2) )";

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);
        std::string expected = proc.get_proc_body().to_string();
        expected = trim(expected);

        EXPECT_EQ(output, expected);

        sample = {"(", "(", "lambda", "x", "x", ")", "3", "4", "5", "6", ")" };
        Env new_env(sample);

        output = "( begin )";

        arg = new_env.get_member(pos);
        Procedure new_proc(arg);
        std::string new_expected = new_proc.get_proc_body().to_string();
        new_expected = trim(new_expected);

        EXPECT_EQ(output, new_expected); 

        sample = {"(", "define", "(", "square", "x", ")", "(", "*", "x", "(", "+", "2", "x", ")", ")"};
        Env last_env(sample);

        output = "( begin ( + 2 x ) )";

        arg = last_env.get_member(pos);
        Procedure last_proc(arg);
        std::string new_expected2 = last_proc.get_proc_body().to_string();
        new_expected2 = trim(new_expected2);

        EXPECT_EQ(output, new_expected2); 
    }
}