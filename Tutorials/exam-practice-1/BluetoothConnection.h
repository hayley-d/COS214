#ifndef BLUETOOTHCONNECTION_H
#define BLUETOOTHCONNECTION_H
#include "Connection.h"

class BluetoothConnection : public Connection{
public:
    BluetoothConnection() = default;
    void connect();
    ~BluetoothConnection() = default;
};
#endif //BLUETOOTHCONNECTION_H
