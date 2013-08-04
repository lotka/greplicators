#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <random>
#include <fstream>

#include "position.h"
#include "genome.h"

//World geometry
int const SPACE_DIMENSIONS = 3;
int const WORLD_SIZE = 2;

//Probability distribution
#define DISTRIBUTION_DIRECTION      0
#define DISTRIBUTION_BINARY         1
#define DISTRIBUTION_GENOME         2
#define DISTRIBUTION_ANIMAL         3
#define DISTRIBUTION_WORLD_POSITION 4

//Object types enumerated
#define TYPE_ENTITY   0
#define TYPE_ANIMAL   1
#define TYPE_FOOD     2
#define TYPE_PARASITE 3

//Forward declaration of entity
class entity;

typedef std::set<entity *> entitySet;

/*! Entity
 *
 */

class entity
{
public:
    /*! update : virtual function
     *
     * @param entitySet : passes
     * @return void :
     */
    virtual void update(entitySet collodingEntitySet) = 0;

    /* */
    virtual void render();
    virtual int eat() = 0;
    virtual void fight() = 0;
    position getPosition();

    /*! comparePositionWith
     *
     * @param entity : 
     * @return 
     */
    int comparePositionWith(entity &other);


    /*! alive : check for life
     *
     * @return bool : life signs
     */
    bool alive();


    /*! alive : check for life
     *
     * @return bool : life signs
     */
    int getType() { return type; }

protected:
    //0 Pure entity, 1 Animal, 2 Food, 3 Parasite
    int type;
    int age;
    int hp;
    position currentPosition;
    genome theGenome;
};


#endif /* ENTITY_H */
