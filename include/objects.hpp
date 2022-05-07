#pragma once

#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

extern bool ERROR_FLAG1;
extern bool ERROR_FLAG2;

class Op {
    public:
        Op();
        ~Op();
        std::string get_expr_type() const;
        std::string get_expr_value() const;
        Procedure get_proc() const;
        bool check_native_procedure() const;
        std::string apply(std::vector<std::string>& expr);
        std::string apply();
        Op(std::string &val);
        Op(std::string(*new_func) (std::vector<std::string>&));
        Op(Procedure &proc_);

    private:
        std::string value;
        std::string type;
        std::string (*func) (std::vector<std::string>&);
        Procedure proc;
        bool native_proc;
};

#endif 