#include "../include/Passwd.hpp"

void Passwd::Retrieve(std::vector<SystemUser> *ul)
{
    // read /etc/shadow
    ShadowDB::Init();
    // open /etc/passwd
    std::ifstream infile("/etc/passwd");
    for(std::string line; getline(infile, line);)
    {
        // split everything by colon
        std::vector<std::string> items = Passwd::split(line, ':');
        // create new instance of user
        SystemUser user;
        if (items.size() > 6)
        {
            user.Name = items[0];
            user.UID = std::stoi(items[2]);
            user.GID = std::stoi(items[3]);
            user.Login = ShadowDB::IsLogin(user.Name);
            user.Shell = items[6];
            user.RetrieveGroups();
        }

        ul->push_back(user);
    }
}

std::vector<std::string> &Passwd::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Passwd::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
