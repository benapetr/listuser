//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/Terminal.hpp"

void Terminal::Write(std::string text)
{
    std::cout << text << std::endl;
}

Terminal::Terminal(int c, char *v[])
{
    int i = 0;
    while (i < c)
    {
        this->Parameters.push_back(std::string(v[i]));
        i++;
    }
}

bool Terminal::Parse()
{
    return true;
}

std::string Terminal::b2s(bool text)
{
    if (text)
    {
        return "True";
    }
    return "False";
}

std::string Terminal::p2s(Property property)
{
    switch (property)
    {
        case Yes:
            return "Yes";
        case No:
            return "No";
        case Unknown:
            return "Unknown";
    }
    return "";
}

void Terminal::PrintUsers(std::vector<SystemUser> user)
{
    unsigned int c = 0;
    if (user.size() == 0)
    {
        Write("There are no users on this system");
        return;
    }
    Write("+--------------------+-----------+----------+--------+---------------------+");
    Write("|Username:           |Is root: * |Login:    |UID:    |Groups:              |");
    Write("+--------------------+-----------+----------+--------+---------------------+");
    while (c < user.size())
    {
        Write("|" + Resize(user[c].Name, 20) +
              "|" + Resize(p2s(user[c].IsRoot()), 11) +
              "|" + Resize(p2s(user[c].IsAbleToLog()), 10) +
              "|" + Resize(i2s(user[c].GetUID()), 8) +
              "|" + Resize(user[c].GroupsString(), 21) + "|"
              );
        c++;
    }
    Write("+--------------------+-----------+----------+--------+---------------------+");
    Write(" * This property is based on user ID as well as SUDO policies,\n"\
          "   proper detection of this property requires this tool to be\n"\
          "   run with superuser privileges");
}

std::string Terminal::i2s(int x)
{
    std::ostringstream s;
    s << x;
    return s.str();
}

std::string Terminal::Resize(std::string text, unsigned int size)
{
    if (text.length() == size)
    {
        return text;
    }
    if (text.length() > size)
    {
        text = text.substr(0, size - 3);
        text += "...";
        return text;
    } else
    {
        while (text.length() < size)
        {
            text += " ";
        }
        return text;
    }
}
