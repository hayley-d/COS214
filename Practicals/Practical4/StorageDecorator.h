#ifndef STORAGEDECORATOR_H
#define STORAGEDECORATOR_H
#include "FarmDecorator.h"

class StorageDecorator : public FarmDecorator {
public:
    void applyEnhancement() override;

    ~StorageDecorator() override = default;

protected:
    //used to add an extra barn to the farm unit
    void addExtraBarn();

    //returns the free storage capacity after addin a barn
    int getLeftoverCapacity();
};
#endif //STORAGEDECORATOR_H
