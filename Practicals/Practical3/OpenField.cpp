#include "OpenField.h"

    void OpenFieldInfantry::move(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldInfantry moves in direction " << direction << std::endl;
    }

    void OpenFieldInfantry::fight(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldInfantry fights in direction " << direction << std::endl;
    }



    void OpenFieldCavalry::move(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldCavalry moves in direction " << direction << std::endl;
    }

    void OpenFieldCavalry::fight(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldCavalry fights in direction " << direction << std::endl;
    }



    void OpenFieldArtillery::move(Direction direction) {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldCavalry moves in direction " << direction << std::endl;
    }

    void OpenFieldArtillery::fight(Direction direction) {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        //std::cout << "OpenFieldCavalry fights in direction " << direction << std::endl;
    }
