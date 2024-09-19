#ifndef DEVICETYPE_H
#define DEVICETYPE_H
#include <ostream>

/**
* @enum DeviceType
* @brief Enum representing different device types
*/
enum DeviceType {
    Light,
    Thermostat,
    Door,
};

/**
* @brief Overloads the output stream operator to print the string representation of the DeviceType Enum.
* @param os The output stream.
* @param deviceType The DeviceType enum value.
* @return The output stream with the string representation of the DeviceType enum.
*/
inline std::ostream& operator<<(std::ostream& os, DeviceType deviceType) {
    if(deviceType == Light) {
        os << "Light";
    } else if(deviceType == Thermostat) {
        os << "Thermostat";
    } else {
        os << "Door";
    }
    return os;
}
#endif //DEVICETYPE_H
