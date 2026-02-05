#include "ServerGroup.hpp"


ServerGroup::ServerGroup(int size)
{
    spServer = 0;
    servers = new int[size];
    this->size = size;
    for(int i = 0; i < size; i++){
        servers[i] = 0;
    }
}

ServerGroup::ServerGroup(const ServerGroup & orig)
{
    deepCopy(orig);
}

ServerGroup::~ServerGroup()
{
    delete [] servers;
}

ServerGroup & ServerGroup::operator=(const ServerGroup & right)
{
    if(this == &right)
        return *this;
    delete [] servers;
    deepCopy(right);

    return *this;
}

inline void ServerGroup::deepCopy(const ServerGroup & orig)
{
    spServer = orig.spServer;
    freeServer = orig.freeServer;
    size = orig.size;

    for(int i = 0; i < size; i++){
        servers[i] = orig.servers[i];
    }
}

int ServerGroup::getSize() const
{
    return size;
}

int ServerGroup::getServer(int index) const
{
    return servers[index];
}

bool ServerGroup::spServerFree() const
{
    return (spServer == 0);
}

bool ServerGroup::serverFree()
{
    for(int i = 0; i < size; i++){
        if(servers[i] == 0){
            freeServer = i;
            return true;
        }
    }

    return false;  // Could not find a free server
}

void ServerGroup::useServer(int avTransTime)
{
    servers[freeServer] = avTransTime;
}

void ServerGroup::usespServer(int avTransTime)
{
    spServer = avTransTime;
}

void ServerGroup::decServers()
{
    if(spServer)
        --spServer;
    
    for(int i = 0; i < size; i++){
        if(servers[i])
            --servers[i];
    }
}

