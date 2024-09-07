#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H
#include "FarmDecorator.h"

class FertilizerDecorator : public FarmDecorator {
public:
    void applyEnhancement() override;

    ~FertilizerDecorator() override = default;

protected:
    //apply fertilizer to enhance crop yield
    void increaseProduction();

    //harvest crops
    void harvest();
};
#endif //FERTILIZERDECORATOR_H
