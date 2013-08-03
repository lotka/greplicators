#ifndef FOOD_H
#define FOOD_H

#include "entityCommon.h"

class food : public entity
{
    genome theGenome;
    int foodValue, maxFoodValue;
public:
    food();
    void update();
    void update(entitySet collidingEntitySet);
    int getFoodValue() { return maxFoodValue; }
};

#endif /*FOOD_H*/
