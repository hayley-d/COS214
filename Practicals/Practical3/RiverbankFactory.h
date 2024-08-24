#ifndef RIVERBANKFACTORY_H
#define RIVERBANKFACTORY_H
#include "LegionFactory.h"
#include "Riverbank.h" // Includes all the Riverbank units

class RiverbankFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new RiverbankInfantry();
    }

    Cavalry* createCavalry() override {
        return new RiverbankCavalry();
    }

    Artillery* createArtillery() override {
        return new RiverbankArtillery();
    }

    Legion * createLegion() override {
        return new Legion();
    }

    ~RiverbankFactory() override;
};
#endif //RIVERBANKFACTORY_H
