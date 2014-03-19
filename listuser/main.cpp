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
    // fetch the list of all users in the system
    vector<SystemUser> Users;
    // load the list of users with all records provided by passwd
    Passwd::Retrieve(&Users);
    Terminal::Write("Listing of all users in the system:");
    Terminal::PrintUsers(Users);
    delete t;
    return 0;
}
