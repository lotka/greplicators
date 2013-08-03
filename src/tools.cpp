#include "tools.h"

////////////////////////////////////////////////////////////////////////////////////////
// generateEntities
////////////////////////////////////////////////////////////////////////////////////////
bool generateEntities(entitySet &targetSet)
{

    for(int i = 0; i < 1; ++i)
    {
        targetSet.insert(new food);
        targetSet.insert(new animal);
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
// getCollidingEntities
////////////////////////////////////////////////////////////////////////////////////////
int getValueFromDistribution(int ID)
{
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> positionDistribution(0, SPACE_DIMENSIONS - 1);
    static std::uniform_int_distribution<int> binaryDistribution(0,1);
    static std::uniform_int_distribution<int> genomeDistribution(0,100);
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
