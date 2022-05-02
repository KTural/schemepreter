#pragma once 

#ifndef PROCS_HPP
#define PROCS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

std::string print(std::vector<std::string> &expr);
std::string add(std::vector<std::string>&vv);
std::string subtract(std::vector<std::string>&vv);
std::string divide(std::vector<std::string>&vv);
std::string multiply(std::vector<std::string>&vv);

std::string equal(std::vector<std::string>&vv);
std::string not_equal(std::vector<std::string>&vv);
std::string less_than(std::vector<std::string>&vv);
std::string less_than_or_equal(std::vector<std::string>&vv);
std::string greater_than(std::vector<std::string>&vv);
std::string greater_than_or_equal(std::vector<std::string>&vv);

std::string scheme_quit(std::vector<std::string>&vv);

#endif