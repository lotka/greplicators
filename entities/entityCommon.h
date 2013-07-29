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

int const SPACE_DIMENSIONS = 1;
int const WORLD_SIZE = 2;

#define DISTRIBUTION_POSITION 0
#define DISTRIBUTION_BINARY 1
#define DISTRIBUTION_GENOME 2


#define LOGREPORT(MSG) std::cout << MSG << std::endl;
#define LOGDEBUG(MSG) logReport << MSG << std::endl;
#define LOGBOTH(MSG) logReport << MSG << std::endl; std::cout << MSG << std::endl;

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
    virtual void render();
    position getPosition();
    int comparePositionWith(entity &other);
protected:
    int age;
    position currentPosition;
    genome theGenome;
};


#endif /* ENTITY_H */

