#pragma once

#ifndef Builder_HPP
#define Builder_HPP

#include <string>
#include <vector>

class Builder {
    public:
        Builder();
        ~Builder();
        std::string get_str() const;
        Procedure get_proc() const;
        Builder(std::string &&new_str);
        Builder(Procedure &procedure);

    private:
        std::string cur_str;
        Procedure proc;
};

#endif