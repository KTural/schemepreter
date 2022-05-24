#include "../include/procedure.hpp"

Procedure::Procedure() = default;
Procedure::~Procedure() = default;

Env Procedure::get_proc_arg_list() const{
    return proc_arg_list;
}

Env Procedure::get_proc_body() const{
    return proc_body;
}

Procedure::Procedure(Env &expr) {
    proc_arg_list = expr.get_member(1);
    std::vector<std::string> temp;
    
    temp.push_back("(");
    temp.push_back("begin");
    
    for (size_t i = 2; i < expr.get_num_exprs(); i++) {
        add_env(temp, expr.get_member(i));
    }

    temp.push_back(")");

    proc_body = Env(temp);
}

void Procedure::add_env(std::vector<std::string>&expr, Env env) const {
    std::vector<std::string> temp = env.get_env();
    for (size_t i = 0; i < temp.size(); i++) {
        expr.push_back(temp[i]);
    }
}
