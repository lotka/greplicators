#ifndef ANIMAL_H
#define ANIMAL_H

#include "entityCommon.h"

/*!
\class animal
The main actor in this simulation
*/

class animal : public entity
{

    int energy;
    int undisgestedFood;
    genome animalGenome;
public:
    animal();
    virtual void update();
    void update(entitySet collodingEntitySet);
    int compareGenomeWith(genome other);
    bool fightWith();
};

#endif /*ANIMAL_H*/
