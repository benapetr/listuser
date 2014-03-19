#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "../include/SystemUser.hpp"

class Terminal
{
    public:
        static void Write(std::string text);
        Terminal(int c, char *v[]);
        static void PrintUsers(std::vector<SystemUser> user);
        bool Parse();
    protected:
    private:
        static std::string Resize(std::string text, unsigned int size);
        static std::string b2s(bool text);
        static std::string p2s(Property property);
        static std::string i2s(int x);
        std::list<std::string> Parameters;
};

#endif // TERMINAL_H
