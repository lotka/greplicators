#include "tools.h"

////////////////////////////////////////////////////////////////////////////////////////
// generateEntities
////////////////////////////////////////////////////////////////////////////////////////
bool generateEntities(entitySet &targetSet)
{
    
    for(int i = 0; i < 2; ++i)
    {
        targetSet.insert(new animal);
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

    switch(ID)
    {
        case 0:
        return positionDistribution(generator);
        case 1:
        return binaryDistribution(generator);
        case 2:
        return 0;
    }
}
