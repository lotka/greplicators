#include "tools.h"
#include <cmath>

////////////////////////////////////////////////////////////////////////////////////////
// generateEntities
////////////////////////////////////////////////////////////////////////////////////////
bool generateEntities(entitySet &targetSet, double animalDensity, double foodDensity)
{

    const double area = pow((double) ( WORLD_SIZE + WORLD_SIZE - 1 ),(double) SPACE_DIMENSIONS );
    const double animalNumber = area * animalDensity;
    const double foodNumber = area * foodDensity;

    std::cout << "World area =  " << area << std::endl;
    std::cout << "Generating " << (int)animalNumber << " animals and " << (int)foodNumber << " food entites" << std::endl;

    for(int i = 0; i < (int)animalNumber; ++i)
    {
        targetSet.insert(new animal);
    }
      
    for(int i = 0; i < (int)foodNumber; ++i)
    {
        targetSet.insert(new food);
    }


    return true;
}
////////////////////////////////////////////////////////////////////////////////////////
// getCollidingEntities
////////////////////////////////////////////////////////////////////////////////////////
entitySet getCollidingEntities(entitySet::iterator current, entitySet &referenceSet)
{
    entitySet collodingEntitySet;

    for(entitySet::iterator it = referenceSet.begin(); it != referenceSet.end(); it++)
    {
        if(it == current )
        {
            continue;
        }

        if( (*current)->comparePositionWith( **it ) )
        {
            collodingEntitySet.insert(*it);
        }

    }

    //std::cout << std::endl << collodingEntitySet.size() << std::endl;

    return collodingEntitySet;
}

////////////////////////////////////////////////////////////////////////////////////////
// getValueFromDistribution
////////////////////////////////////////////////////////////////////////////////////////
int getValueFromDistribution(int ID)
{
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> positionDistribution(0, SPACE_DIMENSIONS - 1);
    static std::uniform_int_distribution<int> binaryDistribution(0,1);
    static std::uniform_int_distribution<int> genomeDistribution(0,10000);
    static std::uniform_int_distribution<int> animalDistribution(0,3);
    static std::uniform_int_distribution<int> worldPositionDistribution(-WORLD_SIZE,WORLD_SIZE);

    switch(ID)
    {
        case 0:
        return positionDistribution(generator);
        case 1:
        return binaryDistribution(generator);
        case 2:
        return genomeDistribution(generator);
        case 3:
        return animalDistribution(generator);
        case 4:
        return worldPositionDistribution(generator);
    }
}
