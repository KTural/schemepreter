#include "../include/operations.hpp"
#include <gtest/gtest.h>

namespace {
    // Addition operation testing :

    TEST(OperationsTestAddition, AdditionSimple) {
        std::vector<std::string> sample = {"+", "2", "3"};
        auto expected = "5";
        EXPECT_EQ(expected, add(sample));
    }

    TEST(OperationsTestAddition, AdditionNested) {
        std::vector<std::string> sample = {"+", "2", "2", "3", "2"};
        auto expected = "9";
        EXPECT_EQ(expected, add(sample));
    }

    TEST(OperationsTestAddition, AdditionEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, add(sample));
    }

    TEST(OperationsTestAddition, AdditionPartialValues) {
        std::vector<std::string> sample = {"+", "3" "+", "3"};
        auto expected = "6";
        EXPECT_EQ(expected, add(sample));
    }

    TEST(OperationsTestAddition, AdditionDouble) {
        std::vector<std::string> sample = {"+", "3.99", "4.891"};
        auto expected = "8.881";
        EXPECT_EQ(expected, add(sample));
    }

    TEST(OperationsTestAddition, AdditionInvalidOperand) {
        std::vector<std::string> sample = {"+", "10", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, add(sample));
    }

    // Subtraction operation testing :

    TEST(OperationsTestSubtraction, SubtractionSimple) {
        std::vector<std::string> sample = {"2", "3"};
        auto expected = "-1";
        EXPECT_EQ(expected, subtract(sample));
    }

    TEST(OperationsTestSubtraction, SubtractionNested) {
        std::vector<std::string> sample = {"2", "2", "3", "2"};
        auto expected = "-5";
        EXPECT_EQ(expected, subtract(sample));
    }

    TEST(OperationsTestSubtraction, SubtractionEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, subtract(sample));
    }

    TEST(OperationsTestSubtraction, SubtractionPartialValues) {
        std::vector<std::string> sample = {"-", "3" "-", "2"};
        auto expected = "-5";
        EXPECT_EQ(expected, subtract(sample));
    }

    TEST(OperationsTestSubtraction, SubtractionDouble) {
        std::vector<std::string> sample = {"-", "3.99", "4.891"};
        auto expected = "-8.881";
        EXPECT_EQ(expected, subtract(sample));
    }

    TEST(OperationsTestSubtraction, SubtractionInvalidOperand) {
        std::vector<std::string> sample = {"-", "10", "-", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, subtract(sample));
    }

    // Division operation testing :

    TEST(OperationsTestDivision, DivisionSimple) {
        std::vector<std::string> sample = {"2", "3"};
        auto expected = "0.666667";
        EXPECT_EQ(expected, divide(sample));
    }

    TEST(OperationsTestDivision, DivisionNested) {
        std::vector<std::string> sample = {"2", "2", "3", "2"};
        auto expected = "0.166667";
        EXPECT_EQ(expected, divide(sample));
    }

    TEST(OperationsTestDivision, DivisionEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, divide(sample));
    }

    TEST(OperationsTestDivision, DivisionDouble) {
        std::vector<std::string> sample = {"3.99", "4.891"};
        auto expected = "0.815784";
        EXPECT_EQ(expected, divide(sample));
    }

    TEST(OperationsTestDivision, DivisionInvalidOperand) {
        std::vector<std::string> sample = {"/", "10", "/", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, divide(sample));
    }

    // Multiplication operation testing :

    TEST(OperationsTestMultiplication, MultiplicationSimple) {
        std::vector<std::string> sample = {"2", "3"};
        auto expected = "6";
        EXPECT_EQ(expected, multiply(sample));
    }

    TEST(OperationsTestMultiplication, MultiplicationNested) {
        std::vector<std::string> sample = {"2", "2", "3", "2"};
        auto expected = "24";
        EXPECT_EQ(expected, multiply(sample));
    }

    TEST(OperationsTestMultiplication, MultiplicationEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, multiply(sample));
    }

    TEST(OperationsTestMultiplication, MultiplicationDouble) {
        std::vector<std::string> sample = {"3.99", "4.891"};
        auto expected = "19.5151";
        EXPECT_EQ(expected, multiply(sample));
    }

    TEST(OperationsTestMultiplication, MultiplicationInvalidOperand) {
        std::vector<std::string> sample = {"*", "10", "*", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, multiply(sample));
    }

    // Equality operation testing :
    
    TEST(OperationsTestEquality, EqualitySimple) {
        std::vector<std::string> sample = {"2", "3"};
        auto expected = "#f";
        EXPECT_EQ(expected, equal(sample));

        sample = {"2", "2"};
        expected = "#t";
        EXPECT_EQ(expected, equal(sample));
    }

    TEST(OperationsTestEquality, EqualityNested) {
        std::vector<std::string> sample = {"2", "2", "3", "2"};
        auto expected = "#f";
        EXPECT_EQ(expected, equal(sample));

        sample = {"2", "2", "2", "2"};
        expected = "#t";
        EXPECT_EQ(expected, equal(sample));
    }

    TEST(OperationsTestEquality, EqualityEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, equal(sample));
    }

    TEST(OperationsTestEquality, EqualityDouble) {
        std::vector<std::string> sample = {"3.99", "4.891"};
        auto expected = "#f";
        EXPECT_EQ(expected, equal(sample));

        sample = {"4.99", "4.9900"};
        expected = "#t";
        EXPECT_EQ(expected, equal(sample));
    }

    TEST(OperationsTestEquality, EqualityInvalidOperand) {
        std::vector<std::string> sample = {"10", "#t", "10", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, equal(sample));
    }

    // Logical Not operation testing :

    TEST(OperationsTestLogicalNot, LogicalNotSimple) {
        std::vector<std::string> sample = {"2"};
        auto expected = "#f";
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"-2"};
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"0"};
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"1"};
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"#t"};
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"#f"};
        expected = "#t";
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"#t"};
        expected = "#f";
        EXPECT_EQ(expected, logical_not(sample));
    }

    TEST(OperationsTestLogicalNot, LogicalNotNested) {
        std::vector<std::string> sample = {"#t", "#f", "#t", "#f"};
        auto expected = "#f";
        EXPECT_EQ(expected, logical_not(sample));

        sample = {"#f", "#t", "=", "#t", "#f"};
        expected = "#t";
        EXPECT_EQ(expected, logical_not(sample));   
    }

    TEST(OperationsTestLogicalNot, LogicalNotEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, logical_not(sample));
    }

    TEST(OperationsTestLogicalNot, LogicalNotDouble) {
        std::vector<std::string> sample = {"3.99"};
        auto expected = "#f";
        EXPECT_EQ(expected, logical_not(sample));
    }

    TEST(OperationsTestLogicalNot, LogicalNotInvalidOperand) {
        std::vector<std::string> sample = {"not", "10", "not", "#t", "not", "0"};
        auto expected = "";
        EXPECT_EQ(expected, logical_not(sample));
    }

    // Less Than operation testing :

    TEST(OperationsTestLessThan, LessThanSimple) {
        std::vector<std::string> sample = {"<", "2", "3"};
        auto expected = "#t";
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<", "4", "2"};
        expected = "#f";
        EXPECT_EQ(expected, less_than(sample));
    }

    TEST(OperationsTestLessThan, LessThanNested) {
        std::vector<std::string> sample = {"<", "2", "2", "3", "2"};
        auto expected = "#f";
        EXPECT_EQ(expected, less_than(sample));
    }

    TEST(OperationsTestLessThan, LessThanEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, less_than(sample));
    }

    TEST(OperationsTestLessThan, LessThanDouble) {
        std::vector<std::string> sample = {"<", "3.99", "3.991"};
        auto expected = "#t";
        EXPECT_EQ(expected, less_than(sample));
    }

    TEST(OperationsTestLessThan, LessThanInvalidOperand) {
        std::vector<std::string> sample = {"<", "10", "<", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<", "10", "#t"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<", "#t", "10"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<", "#t", "#f"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<", "10", "<", "#t", "#f"};
        EXPECT_EQ(expected, less_than(sample));
    }

    // Less Than Or Equal operation testing

    TEST(OperationsTestLessThanOrEqual, LessThanOrEqualSimple) {
        std::vector<std::string> sample = {"<=", "2", "3"};
        auto expected = "#t";
        EXPECT_EQ(expected, less_than_or_equal(sample));

        sample = {"<=", "4", "2"};
        expected = "#f";
        EXPECT_EQ(expected, less_than_or_equal(sample));

        sample = {"<=", "4", "4"};
        expected = "#t";
        EXPECT_EQ(expected, less_than_or_equal(sample));
    }

    TEST(OperationsTestLessThanOrEqual, LessThanOrEqualNested) {
        std::vector<std::string> sample = {"<=", "2", "2", "3", "2"};
        auto expected = "#f";
        EXPECT_EQ(expected, less_than_or_equal(sample));
    }

    TEST(OperationsTestLessThanOrEqual, LessThanOrEqualEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, less_than_or_equal(sample));
    }

    TEST(OperationsTestLessThanOrEqual, LessThanOrEqualDouble) {
        std::vector<std::string> sample = {"<=", "3.99", "3.991"};
        auto expected = "#t";
        EXPECT_EQ(expected, less_than_or_equal(sample));
    }

    TEST(OperationsTestLessThanOrEqual, LessThanOrEqualInvalidOperand) {
        std::vector<std::string> sample = {"<=", "10", "<=", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<=", "10", "#t"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<=", "#t", "10"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<=", "#t", "#f"};
        EXPECT_EQ(expected, less_than(sample));

        sample = {"<=", "10", "<=", "#t", "#f"};
        EXPECT_EQ(expected, less_than(sample));
    }

    // Greater Than operation testing :

    TEST(OperationsTestGreaterThan, GreaterThanSimple) {
        std::vector<std::string> sample = {">", "2", "3"};
        auto expected = "#f";
        EXPECT_EQ(expected, greater_than(sample));

        sample = {">", "4", "2"};
        expected = "#t";
        EXPECT_EQ(expected, greater_than(sample));
    }

    TEST(OperationsTestGreaterThan, GreaterThanNested) {
        std::vector<std::string> sample = {">", "2", "2", "3", "2"};
        auto expected = "#f";
        EXPECT_EQ(expected, greater_than(sample));
    }

    TEST(OperationsTestGreaterThan, GreaterThanEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, greater_than(sample));
    }

    TEST(OperationsTestGreaterThan, GreaterThanDouble) {
        std::vector<std::string> sample = {">", "3.992", "3.991"};
        auto expected = "#t";
        EXPECT_EQ(expected, greater_than(sample));
    }

    TEST(OperationsTestGreaterThan, GreaterThanInvalidOperand) {
        std::vector<std::string> sample = {">", "10", ">", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, greater_than(sample));

        sample = {">", "10", "#t"};
        EXPECT_EQ(expected, greater_than(sample));

        sample = {">", "#t", "10"};
        EXPECT_EQ(expected, greater_than(sample));

        sample = {">", "#t", "#f"};
        EXPECT_EQ(expected, greater_than(sample));

        sample = {">", "10", ">", "#t", "#f"};
        EXPECT_EQ(expected, greater_than(sample));
    }

    // Greater Than Or Equal operation testing

    TEST(OperationsTestGreaterThanOrEqual, GreaterThanOrEqualSimple) {
        std::vector<std::string> sample = {">=", "2", "3"};
        auto expected = "#f";
        EXPECT_EQ(expected, greater_than_or_equal(sample));

        sample = {">=", "4", "2"};
        expected = "#t";
        EXPECT_EQ(expected, greater_than_or_equal(sample));
    }

    TEST(OperationsTestGreaterThanOrEqual, GreaterThanOrEqualNested) {
        std::vector<std::string> sample = {">=", "2", "2", "3", "2"};
        auto expected = "#f";
        EXPECT_EQ(expected, greater_than_or_equal(sample));
    }

    TEST(OperationsTestGreaterThanOrEqual, GreaterThanOrEqualEmpty) {
        std::vector<std::string> sample = {};
        auto expected = "";
        EXPECT_EQ(expected, greater_than_or_equal(sample));
    }

    TEST(OperationsTestGreaterThanOrEqual, GreaterThanOrEqualDouble) {
        std::vector<std::string> sample = {">=", "3.992", "3.991"};
        auto expected = "#t";
        EXPECT_EQ(expected, greater_than_or_equal(sample));
    }

    TEST(OperationsTestGreaterThanOrEqual, GreaterThanOrEqualInvalidOperand) {
        std::vector<std::string> sample = {">=", "10", ">=", "4", "#t"};
        auto expected = "";
        EXPECT_EQ(expected, greater_than_or_equal(sample));

        sample = {">=", "10", "#t"};
        EXPECT_EQ(expected, greater_than_or_equal(sample));

        sample = {">=", "#t", "10"};
        EXPECT_EQ(expected, greater_than_or_equal(sample));

        sample = {">=", "#t", "#f"};
        EXPECT_EQ(expected, greater_than_or_equal(sample));

        sample = {">=", "10", ">=", "#t", "#f"};
        EXPECT_EQ(expected, greater_than_or_equal(sample));
    }

    int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
} 
