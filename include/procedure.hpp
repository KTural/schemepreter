#pragma once 

#ifndef PROC_HPP
#define PROC_HPP

#include <iostream>
#include <string>
#include <vector>
#include "environment.hpp"

class Procedure {
    public:
        Procedure();
        ~Procedure();
        Env get_proc_arg_list() const;
        Env get_proc_body() const;
        Procedure(Env &expr);
    
    private:
        Env proc_arg_list;
        Env proc_body;
        void add_env(std::vector<std::string>&expr, Env env) const;
};

#endif