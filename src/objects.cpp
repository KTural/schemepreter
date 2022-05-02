#include "../include/procedure.hpp"
#include "../include/objects.hpp"

Object::Object() = default;
Object::~Object() = default;

std::string Object::get_expr_type() const {
    return type;
}

std::string Object::get_expr_value() const {
    return value;
}

Procedure Object::get_proc() const{
    return proc;
}

bool Object::check_native_procedure() const {
    return native_proc;
}

std::string Object::apply(std::vector<std::string>&expr) {
    return func(expr);
}

std::string Object::apply() {
    std::vector<std::string> expr;
    return func(expr);
}

Object::Object(std::string &val) {
    value = val;
    type = "variable";
    func = NULL;
    native_proc = false;
}

Object::Object(std::string(*new_func) (std::vector<std::string>&)) {
    func = new_func;
    type = "procedure";
    value = "";
    native_proc = true;
}

Object::Object(Procedure &proc_) {
    proc = proc_;
    type = "procedure";
    value = "";
    native_proc = false;
}