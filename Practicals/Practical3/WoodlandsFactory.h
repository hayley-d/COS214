//(Concrete Factory Class)
#ifndef WOODLANDFACTORY_H
#define WOODLANDFACTORY_H

#include "Legion.h"
#include "LegionFactory.h"
#include "Woodland.h" // Includes all the Woodland units

class WoodlandFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new WoodlandInfantry();
    }

    Cavalry* createCavalry() override {
        return new WoodlandCavalry();
    }

    Artillery* createArtillery() override {
        return new WoodlandArtillery();
    }

    Legion* createLegion() override {
        return new Legion();
    }

    ~WoodlandFactory() override;
};

#endif // WOODLANDFACTORY_H
