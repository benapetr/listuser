//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <string>

class Group
{
    public:
        Group(int Gid);
        Group(const Group& g);
        ~Group();
        int GID;
        std::string GroupName;
        std::vector<std::string> Members;
};

#endif // GROUP_H
