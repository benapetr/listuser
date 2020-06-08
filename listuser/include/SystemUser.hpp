//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef SYSTEMUSER_H
#define SYSTEMUSER_H

#include <string>
#include <vector>
#include "Group.hpp"

enum Property
{
    Yes,
    No,
    Unknown
};

class SystemUser
{
    public:
        SystemUser();
        virtual ~SystemUser();
        SystemUser(const SystemUser& other);
        Property CanLogin();
        Property CanSSH();
        Property IsRoot();
        int GetUID();
        int GetGID();
        std::string GroupsString();
        std::string Name;
        std::string Shell;
        std::string Home;
        Property Root;
        int UID;
        int GID;
        std::vector<Group> Groups;
        Property Login;
    protected:
    private:
};

#endif // SYSTEMUSER_H
