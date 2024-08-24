#ifndef OPENFIELDFACTORY_H
#define OPENFIELDFACTORY_H

#include "LegionFactory.h"
#include "OpenField.h" // Includes all the OpenField units

class OpenFieldFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new OpenFieldInfantry();
    }

    Cavalry* createCavalry() override {
        return new OpenFieldCavalry();
    }

    Artillery* createArtillery() override {
        return new OpenFieldArtillery();
    }

    Legion * createLegion() override {
        return new Legion();
    }

    ~OpenFieldFactory() override;
};
#endif //OPENFIELDFACTORY_H
