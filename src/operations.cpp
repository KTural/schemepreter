#include "../include/operations.hpp"
#include "../include/utils.hpp"

#define TRUE "#t"
#define FALSE "#f"

int arg_error(const std::vector<std::string> &expr, const std::string op) {
    if (expr.size() == 0) {
        std ::cout << "Wrong number of arguments for procedure " << op << std::endl;
        return 1;
    }
    return 0;
}

void operand_error(std::string op) {
    std::cout << "Error! Operand '" + op + "' is not a number" << std::endl;
}

void invalid_num_args() {
    std::cout << "Error! Expected 2 arguments, got 1" << std::endl;
}

void divide_by_zero_error() {
    std::cout << "Error! division by zero" << std::endl;
}

int invalid_logical_arg(const std::vector<std::string> &expr) {
    if (expr.size() == 1) {
        return 0;
    }
    return 1;
}

std::string print(std::vector<std::string> &expr) {
    std::string temp;
    for (size_t i = 0; i < expr.size(); i++) {
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

    if (number(expr[0]) == 0 || expr[0] == op) {
        operand_error(expr[0]);
        return temp;
    }

    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        if (number(expr[i]) == 0) {
            if (expr[i] != op) {
                operand_error(expr[i]);  
            }
            return temp;
        }
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

    if (number(expr[0]) == 0 || expr[0] == op) {
        operand_error(expr[0]);
        return temp;
    }

    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        if (number(expr[i]) == 0) {
            if (expr[i] != op) {
                operand_error(expr[i]);  
            }
            return temp;
        }
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

    if (number(expr[0]) == 0 || expr[0] == op) {
        operand_error(expr[0]);
        return temp;
    }

    double sum = strtod(expr[0].c_str(), NULL);

    if (expr.size() == 1) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 1; i < expr.size(); i++) {
        if (number(expr[i]) == 0) {
            if (expr[i] != op) {
                operand_error(expr[i]);  
            }
            return temp;
        }
        auto val = strtod(expr[i].c_str(), NULL);
        if (val != 0) {
            sum /= val;
        } else {
            divide_by_zero_error();
            return temp;
        }
    }

    ss << sum;
    return ss.str();
}

std::string multiply(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "*";

    if (arg_error(expr, op) == 1) return temp;

    std::stringstream ss;

    if (number(expr[0]) == 0 || expr[0] == op) {
        operand_error(expr[0]);
        return temp;
    }
    
    double sum = strtod(expr[0].c_str(), NULL);

    for (size_t i = 1; i < expr.size(); i++) {
        if (number(expr[i]) == 0) {
            if (expr[i] != op) {
                operand_error(expr[i]);  
            }
            return temp;
        }
        sum *= strtod(expr[i].c_str(), NULL);
    }

    ss << sum;
    return ss.str();
}

int check_logical_equal(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);
    
    if (!(cur_val == second_val) && cur_val != 0 && second_val != 0) {
        return 1;
    }
    return 0;
}

std::string equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "=";

    if (arg_error(expr, op) == 1) return temp;

    if (invalid_logical_arg(expr) == 0) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (number(expr[i]) == 0 && expr[i] != op) {
            operand_error(expr[i]);
            return temp;
        } 
        if (number(expr[i + 1]) == 0 && expr[i + 1] != op) {
            operand_error(expr[i + 1]);
            return temp;
        }
    
        if (check_logical_equal(expr, i) == 1) {
            return FALSE;
        }
    }

    if (expr[expr.size() - 1] == op) return temp;

    return TRUE;
}

std::string logical_not(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "not";

    if (arg_error(expr, op) == 1 || expr[0] == "=" || expr[0] == op) return temp;  

    if ((number(expr[0]) == 1) || 
        (number(expr[0]) == 0 && expr[0] == TRUE)) 
    {
        return FALSE;
    } 
    return TRUE;
    
}

int check_logical_less_than(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val < second_val) && cur_val != 0 && second_val != 0) {
        return 1;
    }
    return 0;
}

std::string less_than(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "<";

    if (arg_error(expr, op) == 1) return temp;

    if (invalid_logical_arg(expr) == 0) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (number(expr[i]) == 0 && expr[i] != op) {
            operand_error(expr[i]);
            return temp;
        } 
        if (number(expr[i + 1]) == 0 && expr[i + 1] != op) {
            operand_error(expr[i + 1]);
            return temp;
        }
        if (check_logical_less_than(expr, i) == 1) {
            return FALSE;
        }
    }
    if (expr[expr.size() - 1] == op) return temp;

    return TRUE;
}

int check_logical_less_than_or_equal(std::vector<std::string> &expr, const size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val <= second_val) && cur_val != 0 && second_val != 0) {
        return 1;
    }
    return 0;
}

std::string less_than_or_equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = "<=";

    if (arg_error(expr, op) == 1) return temp;

    if (invalid_logical_arg(expr) == 0) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (number(expr[i]) == 0 && expr[i] != op) {
            operand_error(expr[i]);
            return temp;
        } 
        if (number(expr[i + 1]) == 0 && expr[i + 1] != op) {
            operand_error(expr[i + 1]);
            return temp;
        }
        if (check_logical_less_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }

    if (expr[expr.size() - 1] == op) return temp;

    return TRUE;
}

int check_logical_greater_than(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val > second_val) && cur_val != 0 && second_val != 0) {
        return 1;
    }
    return 0;
}

std::string greater_than(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = ">";

    if (arg_error(expr, op) == 1) return temp;

    if (invalid_logical_arg(expr) == 0) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (number(expr[i]) == 0 && expr[i] != op) {
            operand_error(expr[i]);
            return temp;
        } 
        if (number(expr[i + 1]) == 0 && expr[i + 1] != op) {
            operand_error(expr[i + 1]);
            return temp;
        }
        if (check_logical_greater_than(expr, i) == 1) {
            return FALSE;
        }
    }

    if (expr[expr.size() - 1] == op) return temp;

    return TRUE;
}

int check_logical_greater_than_or_equal(std::vector<std::string> &expr, size_t &i) {
    auto cur_val = strtod(expr[i].c_str(), NULL);
    auto second_val = strtod(expr[i + 1].c_str(), NULL);

    if (!(cur_val >= second_val) && cur_val != 0 && second_val != 0) {
        return 1;
    }
    return 0;
}

std::string greater_than_or_equal(std::vector<std::string> &expr) {
    std::string temp;
    std::string op = ">=";

    if (arg_error(expr, op) == 1) return temp;

    if (invalid_logical_arg(expr) == 0) {
        invalid_num_args();
        return temp;
    }

    for (size_t i = 0; i < expr.size() - 1; i++) {
        if (number(expr[i]) == 0 && expr[i] != op) {
            operand_error(expr[i]);
            return temp;
        } 
        if (number(expr[i + 1]) == 0 && expr[i + 1] != op) {
            operand_error(expr[i + 1]);
            return temp;
        }
        if (check_logical_greater_than_or_equal(expr, i) == 1) {
            return FALSE;
        }
    }

    if (expr[expr.size() - 1] == op) return temp;

    return TRUE;
}

std::string scheme_quit(std::vector<std::string> &expr) {
    expr = {};
    std::string temp;
    exit(0);
}