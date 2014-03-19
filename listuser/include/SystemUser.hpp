#ifndef SYSTEMUSER_H
#define SYSTEMUSER_H

#include <string>
#include <grp.h>

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
        Property IsAbleToLog();
        Property IsRoot();
        int GetUID();
        int GetGID();
        void RetrieveGroups();
        std::string Name;
        std::string Shell;
        Property Root;
        int UID;
        int GID;
        Property Login;
    protected:
    private:
        //! List of all groups that are later obtained using system fc
        gid_t *Groups;
        //! Size of the list returned by system fc
        int GroupsSize;
};

#endif // SYSTEMUSER_H
