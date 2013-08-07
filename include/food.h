#ifndef FOOD_H
#define FOOD_H

#include "entityCommon.h"

class food : public entity
{
    foodGenome theGenome;
    int foodValue, maxFoodValue, foodTransfer;
public:
    food();
    void update();
    void update(entitySet collidingEntitySet);
    int eat();
    void fight() {  }
};

#endif /*FOOD_H*/
