#include "../include/operations.hpp"

#define TRUE "#t"
#define FALSE "#f"

std::string arg_error(std::vector<std::string> &expr) {
    std::string temp;
    if (expr.size() == 0) {
        return "Wrong number of arguments for procedure +";
    }
    return temp;
}

std::string invalid_logical_arg(std::vector<std::string> &expr) {
    std::string temp;
    if (expr.size() == 1) {
        return TRUE;
    }
    return temp;
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
    arg_error(expr);

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum += strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string subtract(std::vector<std::string> &expr) {
    arg_error(expr);

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum -= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string divide(std::vector<std::string> &expr) {
    arg_error(expr);

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum /= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

std::string multiply(std::vector<std::string> &expr) {
    arg_error(expr);

    std::stringstream ss;
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        sum *= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

int check_logical_and(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) == strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string equal(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_and(expr, i) == 1) {
            return FALSE;
        }
    }

    return TRUE;
}

int check_logical_not_equal(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) != strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string not_equal(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_not_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_less_than(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) < strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string less_than(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_less_than(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_less_than_or_equal(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) <= strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string less_than_or_equal(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_less_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_greater_than(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) > strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string greater_than(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_greater_than(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

int check_logical_greater_than_or_equal(std::vector<std::string> &expr, size_t &i) {
    if (!(strtod(expr[i].c_str(), NULL) >= strtod(expr[i + 1].c_str(), NULL))) {
        return 1;
    }
    return 0;
}

std::string greater_than_or_equal(std::vector<std::string> &expr) {
    invalid_logical_arg(expr);

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (check_logical_greater_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }
    return TRUE;
}

std::string scheme_quit(std::vector<std::string>&vv) {
    std::string temp;
    exit(0);
}