#ifndef CROP_H
#define CROP_H
#include <ostream>
/**
 * @enum Crop
 * @brief Enum representing different types of crops.
 */
enum CropType {
    Corn,
    Wheat,
    Soybeans,
    Sugarcane,
};
/**
 * @class Crop
 * @brief Represents a crop with a specific type and associated harvest yield.
 */
class Crop {
public:
    /**
    * @brief Constructor for the Crop class.
    * @param crop The type of crop.
    *
    * Initializes a Crop object with the specified type and sets the
    * harvest yield based on the crop type.
    */
    Crop(CropType crop) : crop(crop) {
        switch (crop) {
            case Corn:
                harvestYield = 20;
            break;
            case Wheat:
                harvestYield = 40;
            break;
            case Soybeans:
                harvestYield = 15;
            break;
            case Sugarcane:
                harvestYield = 10;
            break;
            default:
                harvestYield = 20;
            break;
        }
    }
private:
    CropType crop; ///< The type of crop.
    int harvestYield;///< The harvest yield associated with the crop.
};


/**
 * @brief Overloads the output stream operator to print the string representation of the Crop enum.
 * @param os The output stream.
 * @param crop The Crop enum value.
 * @return The output stream with the string representation of the Crop enum.
 */
inline std::ostream& operator<<(std::ostream& os, CropType crop) {
    switch (crop) {
        case Corn:
            os << "Corn";
        break;
        case Wheat:
            os << "Wheat";
        break;
        case Soybeans:
            os << "Soybeans";
        break;
        case Sugarcane:
            os << "Sugarcane";
        break;
        default:
            os << "Crop";
        break;
    }
    return os;
}
#endif //CROP_H
