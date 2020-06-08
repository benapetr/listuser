//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/SystemUser.hpp"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <unistd.h>

SystemUser::SystemUser()
{
    //ctor
    this->GID = 0;
    this->UID = 0;
    this->Name = "";
    this->Login = Unknown;
    this->Shell = "";
    this->Home = "";
    this->Root = Unknown;
}

SystemUser::~SystemUser()
{
    //dtor
}

SystemUser::SystemUser(const SystemUser& other)
{
    this->GID = other.GID;
    this->UID = other.UID;
    this->Login = other.Login;
    this->Shell = other.Shell;
    this->Groups = other.Groups;
    this->Name = other.Name;
    this->Home = other.Home;
    this->Root = other.Root;
}

std::string SystemUser::GroupsString()
{
    std::string list = "";
    unsigned int i = 0;
    while (i < this->Groups.size())
    {
        list += this->Groups[i].GroupName;
        list += " ";
        i++;
    }
    return list;
}

Property SystemUser::CanLogin()
{
    if (this->Shell == "/bin/false" || this->Shell == "/usr/sbin/nologin")
    {
        return No;
    }
    return this->Login;
}

Property SystemUser::CanSSH()
{
    std::string ssh_key_path = this->Home + "/.ssh/authorized_keys";

    // Check if authorized_keys file exists
    if (access(ssh_key_path.c_str(), F_OK) == -1)
    {
        // it doesn't exist
        return No;
    }

    if (access(ssh_key_path.c_str(), R_OK) == -1)
    {
        // we can't read it
        return Unknown;
    }
    
    // Try to open it
    // read passwd file
    std::ifstream infile(ssh_key_path.c_str());
    if (infile.fail())
        return Unknown;
        
    for(std::string line; getline(infile, line);)
    {
        if (line.empty())
            continue;
        if (line[0] == '#')
            continue;
        return Yes;
    }
    return No;
}

Property SystemUser::IsRoot()
{
    if (this->UID == 0)
    {
        return Yes;
    }
    return this->Root;
}

int SystemUser::GetUID()
{
    return this->UID;
}

int SystemUser::GetGID()
{
    return this->GID;
}
