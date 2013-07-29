#include "entities/entityCommon.h"
#include "entities/animal.h"
#include "entities/food.h"

/*! generateEntites
 *
 *  Create the intial enviroment and population
 *
 *  @param targetSet : the set in which to generate the starting population
 *
 *  @return bool status
 */
bool generateEntities(entitySet &targetSet);

/*! getCollidingEntites
 *
 *  @param current : tells the function which entity its caller is
 *  @param referenceSet : supplies the function with the enviroment
 *
 *  @return copies of the objects which current object is shares its location
 */
entitySet getCollidingEntities(entitySet::iterator current, entitySet &referenceSet);

/*! getValueFromDistribution
 *
 *  @param type : choose which type of distribution
 *
 *  @return int : value returned
 */
int getValueFromDistribution(int ID);
