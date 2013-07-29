#ifndef FOOD_H
#define FOOD_H

#include "entityCommon.h"

class food : public entity
{
    int value;
public:
    food();
    void update();
    void update(entitySet collodingEntitySet);
    int getValue() { return value; }
};

#endif /*FOOD_H*/
