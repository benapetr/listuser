//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

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
