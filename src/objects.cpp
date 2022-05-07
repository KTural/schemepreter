#include "../include/procedure.hpp"
#include "../include/objects.hpp"

Op::Op() = default;
Op::~Op() = default;

std::string Op::get_expr_type() const {
    return type;
}

std::string Op::get_expr_value() const {
    return value;
}

Procedure Op::get_proc() const{
    return proc;
}

bool Op::check_native_procedure() const {
    return native_proc;
}

std::string Op::apply(std::vector<std::string>&expr) {
    return func(expr);
}

std::string Op::apply() {
    std::vector<std::string> expr;
    return func(expr);
}

Op::Op(std::string &val) {
    value = val;
    type = "variable";
    func = NULL;
    native_proc = false;
}

Op::Op(std::string(*new_func) (std::vector<std::string>&)) {
    func = new_func;
    type = "procedure";
    value = "";
    native_proc = true;
}

Op::Op(Procedure &proc_) {
    proc = proc_;
    type = "procedure";
    value = "";
    native_proc = false;
}