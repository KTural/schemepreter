#include "../include/environment.hpp"

Env::Env() = default;
Env::~Env() = default;

void Env::print_content_of_expr() const {
    for (size_t i = 0; i < env.size(); i++)
        std::cout << env[i] << " ";
    std::cout << std::endl;
}

void Env::clear_content_of_expr() {
    env.clear();
}

Env::Env(std::string &expr) {
    env.push_back("(");
    env.push_back(expr);
    env.push_back(")");
}

Env::Env(std::vector<std::string> &expr) {
    env = expr;
}

std::vector<std::string> Env::get_env() const {
    return env;
}

std::string Env::to_string() const {
    std::string cur_expr = "";
    for (size_t i = 0; i < env.size(); i++){
        cur_expr = cur_expr + env[i] + " ";
    }    
    return cur_expr;
}

std::string Env::get_elem(size_t pos) const {
    std::string cur_elem = env[pos];
    while (cur_elem[cur_elem.size() - 1] == ' ') {
        cur_elem.erase(cur_elem.size() - 1); 
    }
    return cur_elem;
}

void update_env_parantheses(std::vector<std::string> env, size_t &left, size_t &right, size_t &i) {
    if (env[i] == "(") {
        left++;
    } else if (env[i] == ")") {
        right++;
    }
}

size_t Env::get_num_exprs() const {
    size_t left = 0, right = 0;
    size_t temp = 0, flag = 0;

    if (env.size() == 0) {
        return temp;
    }

    if (env.size() == 1) {
        temp = 1;
        return temp;
    }

    for (size_t i = 1; i < env.size() - 1; i++) {
        update_env_parantheses(env, left, right, i);
        if (left == 0 && left == right) {
            temp++;
        } else if (left == 1 && flag == 0) {
            temp++;
            flag = 1;
        } else if (left != 0 && left == right) {
            flag = 0; left = 0; right = 0;
        }
    }
    return temp;
}

size_t Env::get_full_size() const {
    return env.size();
}

void Env::add(std::string expr) {
    env.push_back(expr);
}

Env Env::get_member(size_t pos) const {
    Env cur_env;
    size_t left = 0, right = 0;
    size_t temp = 0;
    size_t flag = 0, flag_read = 0;

    if (env.size() == 1) {
        cur_env = *this;
    }

    for (size_t i = 1; i < env.size() - 1; i++) {
        update_env_parantheses(env, left, right, i);
        if (left == 0 && left == right) {
            temp++;
            if (pos == temp - 1) {
                cur_env.env.push_back(env[i]);
                break;
            }
        } else if (left == 1 && flag == 0) {
            temp++;
            flag = 1;
            if (pos == temp - 1) {
                flag_read = 1;
            }
        } else if (left != 0 && left == right) {
            flag = 0; flag_read = 0;
            left = 0; right = 0;

        } else if (flag_read == 1) {
            cur_env.env.push_back(env[i]);
        }
    }

    if (cur_env.env.size() == 1) {
        return cur_env;
    } else {
        Env new_cur_env;
        new_cur_env.env.push_back("(");
        for (size_t i = 0; i < cur_env.get_full_size(); i++) {
            new_cur_env.env.push_back(cur_env.env[i]);
        }
        new_cur_env.env.push_back(")");
        return new_cur_env;
    }
}