#include "../include/operations.hpp"

#define TRUE "#t"
#define FALSE "#f"

int arg_error(const std::vector<std::string> &expr, const std::string op) {
    if (expr.size() == 0) {
        std ::cout << "Wrong number of arguments for procedure " << op << std::endl;
        return 1;
    }
    return 0;
}

int invalid_logical_arg(const std::vector<std::string> &expr) {
    if (expr.size() == 1) {
        return 0;
    }
    return 1;
}

std::string print(std::vector<std::string> &expr) {
    std::string temp;
    for (int i = 0; i < expr.size(); i++) {
        std::cout << expr[i] << " ";
    }
    std::cout << std::endl;
    return temp;
}

std::string add(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "+";

    if (arg_error(expr, op) == 1) return temp;

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum += strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string subtract(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "-";

    if (arg_error(expr, op) == 1) return temp;

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum -= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string divide(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "/";

    if (arg_error(expr, op) == 1) return temp;

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum /= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string multiply(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "*";

    if (arg_error(expr, op) == 1) return temp;

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum *= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

int check_logical_equal(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val == second_val) && cur_val != 0) {
        return 1;
    }
    return 0;
}

std::string equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "=";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_equal(expr, i) == 1) {
            return FALSE;
        }
    }

    return TRUE;
}

int check_logical_not_equal(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val != second_val)) {
        return 1;
    }
    return 0;
}

std::string not_equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "!=";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_not_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_less_than(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val < second_val)) {
        return 1;
    }
    return 0;
}

std::string less_than(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "<";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_less_than(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_less_than_or_equal(std::vector<std::string> &expr, const size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val <= second_val)) {
        return 1;
    }
    return 0;
}

std::string less_than_or_equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "<=";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_less_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_greater_than(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val > second_val)) {
        return 1;
    }
    return 0;
}

std::string greater_than(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = ">";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_greater_than(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_greater_than_or_equal(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val >= second_val)) {
        return 1;
    }
    return 0;
}

std::string greater_than_or_equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = ">=";

    if (arg_error(expr, op) == 1) return temp;
    if (invalid_logical_arg(expr) == 0) return TRUE;

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_greater_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

std::string scheme_quit(std::vector<std::string> &expr) {
    std::string temp;
    exit(0);
}