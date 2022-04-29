#include "../include/plist.hpp"
#include "../include/procedure.hpp"
#include "../include/structure.hpp"

Builder::Builder() = default;

Builder::~Builder() = default;

std::string Builder::get_str() const {
    return cur_str;
}

Procedure Builder::get_proc() const {
    return proc;
}

Builder::Builder(std::string &&new_str) {
    cur_str = new_str;
}

Builder::Builder(Procedure &procedure) {
    cur_str = "";
    proc = procedure;
}