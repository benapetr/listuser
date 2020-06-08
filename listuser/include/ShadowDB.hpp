//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef SHADOWDB_H
#define SHADOWDB_H

#include <string>
#include <vector>
#include "../include/SystemUser.hpp"

class ShadowUser
{
    public:
        ShadowUser();
        ShadowUser(const ShadowUser& user);
        std::string Name;
        bool Locked;
};

class ShadowDB
{
    public:
        static void Init();
        static Property IsLogin(std::string Name);
    protected:
    private:
        static bool init;
        static std::vector<ShadowUser> Users;
};

#endif // SHADOWDB_H
