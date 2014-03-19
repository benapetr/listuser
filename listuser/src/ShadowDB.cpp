#include "ShadowDB.hpp"

bool ShadowDB::init = false;
std::vector<ShadowUser> ShadowDB::Users;

ShadowUser::ShadowUser()
{
    this->Locked = false;
}

ShadowUser::ShadowUser(const ShadowUser& user)
{
    this->Locked = user.Locked;
    this->Name = user.Name;
}

void ShadowDB::Init()
{
    if (init)
    {
        return;
    }
    init = true;
    // read passwd file
    std::ifstream infile("/etc/shadow");
    for(std::string line; getline(infile, line);)
    {
        ShadowUser user;
        // split everything by colon
        std::vector<std::string> items = split(line, ':');
        if (items.size() > 4)
        {
            user.Name = items[0];
            user.Locked = (items[1].find("*") != std::string::npos) || (items[1].find("!") != std::string::npos);
            Users.push_back(user);
        }
    }
}

Property ShadowDB::IsLogin(std::string UID)
{
    // first we need to find the user
    unsigned int i = 0;
    while (i < Users.size())
    {
        if (Users[i].Name == UID)
        {
            if (Users[i].Locked)
            {
                return No;
            } else
            {
                return Yes;
            }
        }
        i++;
    }
    return Unknown;
}

std::vector<std::string> &ShadowDB::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> ShadowDB::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
