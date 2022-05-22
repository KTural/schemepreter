#include "../include/procedure.hpp"
#include "../include/structure.hpp"
#include <gtest/gtest.h>

namespace {
    TEST(StructureTest, CheckGetStr) {
        auto expr = "define x 3";
        Builder b(expr);

        EXPECT_EQ(expr, b.get_str());
    }

    TEST(StructureTest, CheckGetProc) {
        std::vector<std::string> sample = {"(", "define", "(", "square", "x", ")", "(", "*", "x", "(", "+", "2", "x", ")", ")"};
        Env env(sample);

        std::string output = "( begin ( + 2 x ) ) ";

        size_t pos = 2;
        Env arg = env.get_member(pos);
        Procedure proc(arg);
        
        Builder b(proc);
        auto expected = b.get_proc().get_proc_body().to_string();

        EXPECT_EQ(output, expected);
    }
}