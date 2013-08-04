#ifndef ANIMAL_H
#define ANIMAL_H
 
#include "entityCommon.h"

typedef std::map<int,char *> plan;

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
    void update(entitySet collidingEntitySet);
    int compareGenomeWith(genome other);
    bool fightWith();
};

#endif /*ANIMAL_H*/
