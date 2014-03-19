#ifndef PASSWD_H
#define PASSWD_H

#include <fstream>
#include <sstream>
#include <vector>
#include "../include/SystemUser.hpp"

class Passwd
{
    public:
        static void Retrieve(std::vector<SystemUser> *ul);
    protected:
    private:
        static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
        static std::vector<std::string> split(const std::string &s, char delim);
};

#endif // PASSWD_H
