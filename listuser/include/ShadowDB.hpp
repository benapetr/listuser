#ifndef SHADOWDB_H
#define SHADOWDB_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
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
        static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
        static std::vector<std::string> split(const std::string &s, char delim);
        static bool init;
        static std::vector<ShadowUser> Users;
};

#endif // SHADOWDB_H
