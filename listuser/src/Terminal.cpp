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

bool Terminal::ProcessChar(char x)
{
    switch (x)
    {
        case 'h':
            Terminal::DisplayHelp();
            return false;
    }
    return true;
}

void Terminal::DiplayVersion()
{
    Write("listuser version 1.0.0");
}

void Terminal::DisplayHelp()
{
    Write("Usage: listuser [options]\n\n"\
          "Display a list of all users that exist in this system, including their\n"\
          "properties, such as if this user account is able to login to this system\n"\
          "or, if such user can become root using sudo. Some of the features are only\n"\
          "supported when the tool is started as superuser.\n\n"\
          "Optional parameters:\n"\
          "  --help|-h: Display this help\n"\
          "  --version: Display version\n"\
          "This program is open source, licensed under GNU GPL v 3. "\
          "Source code is located at https://github.com/benapetr/listuser");
}

bool Terminal::Parse()
{
    unsigned int x = 0;
    while (x < this->Parameters.size())
    {
        std::string parameter = this->Parameters[x];
        x++;
        if (parameter.length() > 1 && parameter[0] == '-' && parameter[1] != '-')
        {
            // this is -fdsg like parameter
            unsigned int i = 1;
            while (i < parameter.length())
            {
                if (!Terminal::ProcessChar(parameter[i]))
                {
                    return false;
                }
                i++;
            }
        } else if (parameter == "--version")
        {
            Terminal::DiplayVersion();
            return false;
        } else if (parameter == "--help")
        {
            Terminal::DisplayHelp();
            return false;
        }
    }
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
