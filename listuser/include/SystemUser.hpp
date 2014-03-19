#ifndef SYSTEMUSER_H
#define SYSTEMUSER_H

#include <string>

enum Property
{
    Yes,
    No,
    Unknown
};

class SystemUser
{
    public:
        SystemUser();
        virtual ~SystemUser();
        SystemUser(const SystemUser& other);
        Property IsLocked();
        Property IsRoot();
        int GetUID();
        int GetGID();
        std::string Name;
        std::string Shell;
        Property Root;
        int UID;
        int GID;
        Property Locked;
    protected:
    private:

};

#endif // SYSTEMUSER_H
