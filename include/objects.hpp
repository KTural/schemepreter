#pragma once

#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Object {
    public:
        Object();
        ~Object();
        std::string get_expr_type() const;
        std::string get_expr_value() const;
        Procedure get_proc() const;
        bool check_native_procedure() const;
        std::string apply(std::vector<std::string>& expr);
        std::string apply();
        Object(std::string &val);
        Object(std::string(*new_func) (std::vector<std::string>&));
        Object(Procedure &proc_);

    private:
        std::string value;
        std::string type;
        std::string (*func) (std::vector<std::string>&);
        Procedure proc;
        bool native_proc;
};

#endif 