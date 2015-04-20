//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/SystemUser.hpp"

SystemUser::SystemUser()
{
    //ctor
    this->GID = 0;
    this->UID = 0;
    this->Name = "";
    this->Login = Unknown;
    this->Shell = "";
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

Property SystemUser::IsAbleToLog()
{
    if (this->Shell == "/bin/false" || this->Shell == "/usr/sbin/nologin")
    {
        return No;
    }
    return this->Login;
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
