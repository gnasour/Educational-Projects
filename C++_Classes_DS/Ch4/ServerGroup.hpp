#ifndef SERVER_GROUP_H
#define SERVER_GROUP_H


class ServerGroup
{

     
public:
    ServerGroup(int size);

    // Copy constructor
    ServerGroup(const ServerGroup & orig);

    // Destructor
    ~ServerGroup();

    // Assignment overload operator
    ServerGroup & operator=(const ServerGroup & right);

    int getSize() const;
    int getServer(int index) const;
    bool spServerFree() const;
    bool serverFree();
    void useServer(int avTransTime);
    void usespServer(int avTransTime);
    void decServers();
    void test();
private:
    int *servers;
    int spServer;
    int freeServer;
    int size;
    inline void deepCopy(const ServerGroup & orig);
};

#endif