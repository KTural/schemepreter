#include "../include/utils.hpp"

void print_prompt() {
    std::cout << ">>> ";
}

void check_for_symbols(char &temp, std::string &input, int &left, int &right, int &quotes) {
    if (temp != '\n') {
        input += temp;
    }
    if (temp == '(') {
        left++;
    } else if (temp == ')') {
        right++;
    } else if (temp == '\"') {
        quotes++;
    }
}

std::string read_user_input() {
    std::string input; char temp;
    int left = 0, right = 0, quotes = 0;

    while (true) {
        std::cin.get(temp);
        
        if (temp == ';') {
            while (temp != '\n') {
                std::cin.get(temp);
            }
        }
        check_for_symbols(temp, input, left, right, quotes);

        if (temp == '\n') {
            if (left == 0 && right == 0 && quotes == 0) {
                break;
            }
            if (left != 0 && (left == right) && (quotes == 0 || (quotes & 1) == 0)) {
                break;
            }
            if (left == 0 && right == 0 && (quotes & 1) == 0) {
                break;
            }
            if ((quotes & 1)) {
                input += "\\n";
            }
            else {
                input += " ";
            }
        }
    }
    return input;
}

bool number(const std::string inp) {
    boost::regex re("[0-9]");
    boost::match_results<std::string::const_iterator> what; 
    return boost::regex_search(inp.begin(), inp.end(), what, re, boost::match_default);
}

void replace_substr(std::string &inp, std::string target, std::string res) {
    inp = std::regex_replace(inp, std::regex(target), res);
}

std::vector<std::string> parse_input(std::string &str) {
    replace_substr(str, "\\(", " ( ");
    replace_substr(str, "\\)", " ) ");

    std::stringstream ss(str);
    std::string temp; int flag = 0;
    std::vector<std::string> cur_input, parsed_input;
    
    while (ss >> temp) {
        cur_input.push_back(temp);
    }

    if (str.find("\"") == std::string::npos) {
        return cur_input;
    }
    
    temp = "";

    for (size_t i = 0; i < cur_input.size(); i++) {
        if (cur_input[i].find("\"") != std::string::npos) {
            if (cur_input[i][0] == '\"' && cur_input[i][cur_input[i].size() - 1] == '\"') {
                parsed_input.push_back(cur_input[i]);
                continue;
            }
            flag = 1;
            
            if (cur_input[i][0] == '\"') {
                temp = cur_input[i] + " ";
            } else if (cur_input[i][cur_input[i].size() - 1] == '\"') {
                temp += cur_input[i] + " ";
                parsed_input.push_back(temp);
                temp = "";
                flag = 0;
            } else
                temp += cur_input[i] + " ";
        } else
            if (flag == 0) {
            parsed_input.push_back(cur_input[i]);
        } else
            temp += cur_input[i] + " ";
    }
    return parsed_input;
}