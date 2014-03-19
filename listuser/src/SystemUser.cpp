#include "../include/SystemUser.hpp"

SystemUser::SystemUser()
{
    //ctor
    this->GID = 0;
    this->UID = 0;
    this->Name = "";
    this->Login = Unknown;
    this->Groups = NULL;
    this->GroupsSize = 0;
    this->Shell = "";
    this->Root = No;
}

SystemUser::~SystemUser()
{
    //dtor
    if (Groups != NULL)
    {
        delete[] Groups;
    }
}

SystemUser::SystemUser(const SystemUser& other)
{
    this->GID = other.GID;
    this->UID = other.UID;
    this->Login = other.Login;
    this->Shell = other.Shell;
    this->Groups = other.Groups;
    this->GroupsSize = other.GroupsSize;
    this->Name = other.Name;
    this->Root = other.Root;
}

Property SystemUser::IsAbleToLog()
{
    if (this->Shell == "/bin/false" || this->Shell == "/usr/sbin/nologin")
    {
        return No;
    }
    return this->Login;
}

Property SystemUser::IsRoot()
{
    if (this->UID == 0)
    {
        return Yes;
    }
    return this->Root;
}

void SystemUser::RetrieveGroups()
{
    //int s = 10;
    //gid_t *buffer;
    //buffer = new gid_t[s];

    //while (getgrouplist(this->Name.c_str(), this->GetGID(), buffer, &s) == -1)
    //{
    //    s += 10;
    //    delete[] buffer;
    //    buffer = new gid_t[s];
    //}
    //this->Groups = buffer;
    //this->GroupsSize = s;
}

int SystemUser::GetUID()
{
    return this->UID;
}

int SystemUser::GetGID()
{
    return this->GID;
}
