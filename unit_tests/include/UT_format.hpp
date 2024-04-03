#pragma once
#include <string>

namespace color {
    const std::string RED       =   "\x1b[31m";
    const std::string GREEN     =   "\x1b[32m";
    const std::string ENDC      =   "\033[0m";
    const std::string BOLD      =   "\033[1m";

    //Format utility functions
    std::string output (const std::string &message, const std::string &color)
    {
        return color + message + ENDC;
    }
};
