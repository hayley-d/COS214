#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
public:
    Connection() = default;
    virtual void connect() = 0;
    virtual ~Connection() = default;
};
#endif //CONNECTION_H
