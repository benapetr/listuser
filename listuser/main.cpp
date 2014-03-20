//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include <iostream>
#include <vector>
#include "include/SystemUser.hpp"
#include "include/Passwd.hpp"
#include "include/Terminal.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Terminal *t = new Terminal(argc, argv);
    if (!t->Parse())
    {
        delete t;
        return 0;
    }
    delete t;
    // fetch the list of all users in the system
    vector<SystemUser> Users;
    // load the list of users with all records provided by passwd
    Passwd::Retrieve(&Users);
    Terminal::Write("Listing of all users in the system:");
    Terminal::PrintUsers(Users);
    return 0;
}
