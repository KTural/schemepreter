#pragma once 

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <boost/regex.hpp>

void print_prompt();
std::string read_user_input();
bool number(const std::string input);
void replace_substr(std::string &input, std::string target, std::string res);
std::vector<std::string> parse_input(std::string &str);

#endif