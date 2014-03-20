//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef GROUPDATA_H
#define GROUPDATA_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/Group.hpp"

class GroupData
{
    public:
        static void Init();
        static std::vector<Group> GetGroupsForUN(std::string UN, int gid);
    private:
        static bool loaded;
        static std::vector<Group> Groups;
};

#endif // GROUPDATA_H
