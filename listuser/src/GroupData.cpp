//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/GroupData.hpp"
#include "../include/StringTool.hpp"

bool GroupData::loaded = false;
std::vector<Group> GroupData::Groups;

void GroupData::Init()
{
    if (loaded)
    {
        return;
    }
    loaded = true;
    std::ifstream infile("/etc/group");
    for(std::string line; getline(infile, line);)
    {
        // split everything by colon
        std::vector<std::string> items = StringTool::split(line, ':');
        // create new instance of group
        if (items.size() > 2)
        {
            Group g(std::stoi(items[2]));
            g.GroupName = items[0];
            if (items.size() > 3)
            {
                g.Members = StringTool::split(items[3], ',');
            }
            Groups.push_back(g);
        }
    }
}

std::vector<Group> GroupData::GetGroupsForUN(std::string UN, int gid)
{
    unsigned int c = 0;
    std::vector<Group> grouplist;
    while (c < Groups.size())
    {
        if (Groups[c].GID == gid)
        {
            grouplist.push_back(Groups[c]);
            c++;
            continue;
        }
        // check if this user is a member of this group
        unsigned int u = 0;
        while (u < Groups[c].Members.size())
        {
            if (Groups[c].Members[u] == UN)
            {
                grouplist.push_back(Groups[c]);
                break;
            }
            u++;
        }
        c++;
    }
    return grouplist;
}
