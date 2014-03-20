//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "../include/Passwd.hpp"
#include "../include/StringTool.hpp"

void Passwd::Retrieve(std::vector<SystemUser> *ul)
{
    // read /etc/shadow
    ShadowDB::Init();
    // read /etc/group
    GroupData::Init();
    // open /etc/passwd
    std::ifstream infile("/etc/passwd");
    for(std::string line; getline(infile, line);)
    {
        // split everything by colon
        std::vector<std::string> items = StringTool::split(line, ':');
        // create new instance of user
        SystemUser user;
        if (items.size() > 6)
        {
            user.Name = items[0];
            user.UID = std::stoi(items[2]);
            user.GID = std::stoi(items[3]);
            user.Login = ShadowDB::IsLogin(user.Name);
            user.Groups = GroupData::GetGroupsForUN(user.Name, user.GetGID());
            user.Shell = items[6];
        }

        ul->push_back(user);
    }
}
