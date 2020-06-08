//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/StringTool.hpp"
#include "../include/ShadowDB.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

bool ShadowDB::init = false;
std::vector<ShadowUser> ShadowDB::Users;

ShadowUser::ShadowUser()
{
    this->Locked = false;
}

ShadowUser::ShadowUser(const ShadowUser& user)
{
    this->Locked = user.Locked;
    this->Name = user.Name;
}

void ShadowDB::Init()
{
    if (ShadowDB::init)
        return;

    ShadowDB::init = true;
    
    // read passwd file
    std::ifstream infile("/etc/shadow");
    for(std::string line; getline(infile, line);)
    {
        ShadowUser user;
        // split everything by colon
        std::vector<std::string> items = StringTool::split(line, ':');
        if (items.size() > 4)
        {
            user.Name = items[0];
            user.Locked = (items[1].find("*") != std::string::npos) || (items[1].find("!") != std::string::npos);
            Users.push_back(user);
        }
    }
}

Property ShadowDB::IsLogin(std::string UID)
{
    // first we need to find the user
    unsigned int i = 0;
    while (i < Users.size())
    {
        if (Users[i].Name == UID)
        {
            if (Users[i].Locked)
            {
                return No;
            } else
            {
                return Yes;
            }
        }
        i++;
    }
    return Unknown;
}

