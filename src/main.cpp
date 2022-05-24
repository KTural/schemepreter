#include "../include/utils.hpp"
#include "../include/environment.hpp"
#include "../include/procedure.hpp"
#include "../include/objects.hpp"
#include "../include/operations.hpp"
#include "../include/structure.hpp"

#define FORM_ERROR_IF "ill-formed special form: if"
#define FORM_ERROR_BEGIN "ill-formed special form: begin"
#define FORM_ERROR_DEFINE "ill-formed special form: define"
#define FORM_ERROR_LAMBDA "ill-formed special form: lambda"
#define FORM_ERROR_QUOTE "ill-formed special form: quote"
#define FORM_ERROR_SET "ill-formed special form: set!"

#define VAR_ERROR "Error! Unbound variable: "
#define INVALID_ERROR "Error! Invalid number of expressions: "

bool ERROR_FLAG1 = true;
bool ERROR_FLAG2 = true;

typedef std::map<std::string, Op> Interpreter;

Builder eval(Env &expr, Interpreter &env);
std::string eval_proc(Procedure &proc, Env &args, Interpreter env);

void run_repl(Interpreter &env) {
    print_prompt();
    while (true) {
        ERROR_FLAG1 = true;
        ERROR_FLAG2 = true;

        std::string user_input = read_user_input();
        if (user_input == "") {
            continue; 
        }

        std::vector<std::string> parsed_output = parse_input(user_input);
        Env eval_out = Env(parsed_output);

        std::string res = (eval(eval_out, env)).get_str();
        if (res == "") {
            print_prompt();
            continue;
        }

        std::cout << res << std::endl;
        print_prompt();
    }
}

void load_operations(Interpreter &env) {
    env["print"] = print;
    env["+"] = add;
    env["-"] = subtract;
    env["*"] = multiply;
    env["/"] = divide;
    env["="] = equal;
    env["not"] = logical_not;
    env["<"] = less_than;
    env["<="] = less_than_or_equal;
    env[">"] = greater_than;
    env[">="] = greater_than_or_equal;
    env["exit"] = scheme_quit;
    env["quit"] = scheme_quit;
    run_repl(env);
}

void load_special_keywords(Interpreter &env, std::string keyword = "default") {
    env["if"] = keyword;
    env["begin"] = keyword;
    env["define"] = keyword;
    env["lambda"] = keyword;
    env["quote"] = keyword;
    env["set!"] = keyword;
}

Builder eval_if(Env &expr, Interpreter &env) {       
    Env first_mem = expr.get_member(1);
    Env second_mem = expr.get_member(2);
    std::string cur_expr = (eval(first_mem, env)).get_str();

    if (number(cur_expr) || cur_expr == "#t") {
        return eval(second_mem, env);
    } 

    return Builder("");
}

std::string check_for_symbol(Env &expr, Interpreter &env) {
    Env first_mem = expr.get_member(0);
    std::string inp = first_mem.get_elem(0);

    for (int i = 1; i < expr.get_full_size() - 2; i++) {
        inp = inp + expr.get_elem(i);
    }

    if (env.find(inp) != env.end()) {
        if (env[inp].get_expr_type() == "procedure" && env[inp].check_native_procedure() == true) {
            return env[inp].apply();
        } else {
            return env[inp].get_expr_value();
        }
    } 
    
    return ((VAR_ERROR + inp));
}

Builder check_for_expr(Env &expr, Interpreter &env) {
    std::string cur_expr = expr.get_elem(0);

    if (cur_expr[0] == '#' && cur_expr[1] == '\\') {
        return Builder("Type is not implemented!");
    }

    if ((cur_expr[0] == '\"' && cur_expr[cur_expr.size() - 1] == '\"') || number(cur_expr)) {
        return cur_expr;
    }

    if (env.find(cur_expr) != env.end()) {
        if (env[cur_expr].get_expr_type() == "variable") {
            return env[cur_expr].get_expr_value();
        } else {
            if (ERROR_FLAG1) {
                std::cout << env[cur_expr].get_expr_type() << " ";
            }
            ERROR_FLAG1 = true;
            return cur_expr;
        }
    } else {
        std::string res;
        if (ERROR_FLAG2) {
            res = VAR_ERROR + cur_expr;
        }
        ERROR_FLAG2 = true;
        return res;
    }
}

std::string check_for_proc_and_lambda(Env &cur_expr, Env &expr, Interpreter &env, std::string &proc, int num_exprs) {
    Env first_mem = cur_expr.get_member(0);
    std::string keyword = first_mem.get_elem(0);
    if (keyword == "lambda") {
        Procedure cur_proc = Procedure(cur_expr);
        Env args;
        args.add("(");
        for (int i = 1; i < num_exprs; i++) {
            Env piece = expr.get_member(i);
            std::string res = (eval(piece, env)).get_str();
            args.add(res);
        }
        args.add(")");
        return eval_proc(cur_proc, args, env);
    } else {
        proc = (eval(cur_expr, env)).get_str();
    }
    return "";
}

Builder eval_define(Env &expr, Interpreter &env) {
    if (expr.get_num_exprs() != 3) {
        return Builder(FORM_ERROR_DEFINE);
    } else {
        std::string elem = (expr.get_member(1)).get_elem(0);
        Env second_mem = expr.get_member(2);
        Builder res = eval(second_mem, env);
        if (res.get_str() == "") {
            Procedure proc = res.get_proc();
            env[elem] = proc;
        } else {
            std::string cur_res = res.get_str();
            env[elem] = cur_res;
        }
        return Builder("");
    }
}

Builder eval_set(Env &expr, Interpreter &env) {
    if (expr.get_num_exprs() != 3) {
        return Builder(FORM_ERROR_SET);
    } else {
        std::string elem = (expr.get_member(1)).get_elem(0);
        if (env.find(elem) == env.end()) {
            return Builder(VAR_ERROR + elem);
        }
        Env second_mem = expr.get_member(2);
        std::string res = (eval(second_mem, env)).get_str();
        env[elem] = res;
        return Builder("");
    }
}

Builder eval_quote(Env &expr) {
    if (expr.get_num_exprs() != 2) {
        return Builder(FORM_ERROR_QUOTE);
    } else {
        return expr.get_member(1).to_string();
    }
}

Builder eval_if_more_expr(Env &expr, Interpreter &env) {
    if (expr.get_num_exprs() == 4) {
        Env first_mem = expr.get_member(1);
        Env second_mem = expr.get_member(2);
        Env third_mem = expr.get_member(3);
        std::string cur_expr = (eval(first_mem, env)).get_str();

        if (number(cur_expr)) {
            return eval(second_mem, env);
        }

        if (cur_expr == "#t") {
            return eval(second_mem, env);
        } else {
            return eval(third_mem, env);
        }
    } else {
        return Builder(FORM_ERROR_IF);
    }
}

std::string eval_begin(Env &expr, Interpreter &env) {
    std::string res;
    for (int i = 1; i < expr.get_num_exprs(); i++) {
        Env cur_mem = expr.get_member(i);
        res = (eval(cur_mem, env)).get_str();
    }
    return res;
}

Builder eval_parantheses(Env &expr, Interpreter &env, int num_exprs) {
    Env exprs;
    exprs.add("(");
    for (int i = 0; i < num_exprs; i++) {
        Env cur_member = expr.get_member(i);
        std::string res = (eval(cur_member, env)).get_str();
        
        if (res == "") {
            res = (cur_member.get_member(0)).get_elem(0);
        }
        exprs.add(res);
    }
    exprs.add(")");

    std::vector<std::string> env_args;
    std::string cur_elem = (exprs.get_member(0)).get_elem(0);

    for (int i = 1; i < exprs.get_num_exprs(); i++) {
        env_args.push_back((exprs.get_member(i)).get_elem(0));
    }
    
    if (env.find(cur_elem) != env.end()) {
        if (env[cur_elem].check_native_procedure()) {
            return env[cur_elem].apply(env_args);
        } else {
            Procedure proc = env[cur_elem].get_proc();
            Env new_args;
            new_args.add("(");

            for (int i = 1; i < num_exprs; i++) {
                Env piece = expr.get_member(i);
                std::string res = (eval(piece, env)).get_str();
                new_args.add(res);
            }

            new_args.add(")");
            return eval_proc(proc, new_args, env);
        }

    } else {
        return Builder(VAR_ERROR + cur_elem);
    }
}

std::string eval_proc(Procedure &proc, Env &args, Interpreter env) {
    Env arg_list = proc.get_proc_arg_list();
    Env proc_body = proc.get_proc_body();
    for (int i = 0; i < args.get_num_exprs(); i++) {
        std::string cur_mem_elem = (arg_list.get_member(i)).get_elem(0);
        Env env_mem = args.get_member(i);
        std::string stt = (eval(env_mem, env)).get_str();
        env[cur_mem_elem] = stt;
    }
    std::string res = (eval(proc_body, env)).get_str();
    return res;
}

Builder eval(Env &expr, Interpreter &env) {
    int num_exprs = expr.get_num_exprs();
    if (num_exprs == 1) { 
        if (expr.get_elem(0) == "(" && expr.get_elem(expr.get_full_size() - 1) == ")") {
            return check_for_symbol(expr, env);
        } else {
            return check_for_expr(expr, env);
        }
    } else {
        ERROR_FLAG1 = false; ERROR_FLAG2 = false;
        std::string proc;
        Env first_mem = expr.get_member(0);

        if (first_mem.get_num_exprs() == 1) {
            proc = first_mem.get_elem(0);
        } else {
            return check_for_proc_and_lambda(first_mem, expr, env, proc, num_exprs);
        }

        if (proc == "define") {
            return eval_define(expr, env);
        } else if (proc == "set!") {
            return eval_set(expr, env);
        } else if (proc == "quote") {
            eval_quote(expr);
        } else if (proc == "if") {
            if (expr.get_num_exprs() == 3) {
                return eval_if(expr, env);
            }
            return eval_if_more_expr(expr, env);
        } else if (proc == "lambda") {
            Procedure pr = Procedure(expr);
            return pr;
        } else if (proc == "begin") {
            if (expr.get_num_exprs() < 2) {
                return Builder(FORM_ERROR_BEGIN);
            }
            return eval_begin(expr, env);
        } else {
            return eval_parantheses(expr, env, num_exprs);
        }
    }
    return Builder(INVALID_ERROR + num_exprs);
}

int main() {
    Interpreter env;
    load_operations(env);
    load_special_keywords(env);
    run_repl(env);
    return (0);
}
