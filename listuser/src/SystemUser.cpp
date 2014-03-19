#include "../include/SystemUser.hpp"

SystemUser::SystemUser()
{
    //ctor
    this->GID = 0;
    this->UID = 0;
    this->Name = "";
    this->Locked = Unknown;
    this->Shell = "";
    this->Root = No;
}

SystemUser::~SystemUser()
{
    //dtor
}

SystemUser::SystemUser(const SystemUser& other)
{
    this->GID = other.GID;
    this->UID = other.UID;
    this->Locked = other.Locked;
    this->Shell = other.Shell;
    this->Name = other.Name;
    this->Root = other.Root;
}

Property SystemUser::IsLocked()
{
    return this->Locked;
}

Property SystemUser::IsRoot()
{
    if (this->UID == 0)
    {
        return Yes;
    }
    return this->Root;
}

int SystemUser::GetUID()
{
    return this->UID;
}

int SystemUser::GetGID()
{
    return this->GID;
}
