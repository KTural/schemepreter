#pragma once

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

class Env {
    public:
        Env();
        ~Env();
        void print_content_of_expr() const;
        const void clear_content_of_expr();
        Env(std::string &expr);
        Env(std::vector<std::string> &expr);
        std::vector<std::string> get_env() const;
        std::string to_string() const;
        std::string get_elem(size_t pos) const;
        size_t get_num_exprs() const;
        size_t get_full_size() const;
        void add(std::string expr);
        Env get_member(size_t pos) const;

    private:
        std::vector<std::string> env;
};

#endif