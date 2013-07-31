#include "entityCommon.h"
#include "tools.h"

////////////////////////////////////////////////////////////////////////////////////////
// constructor
////////////////////////////////////////////////////////////////////////////////////////
position::position()
{
    positionVector.resize(SPACE_DIMENSIONS);

    for(int i = 0; i < positionVector.size(); ++i)
    {
        positionVector[i] = getValueFromDistribution(DISTRIBUTION_WORLD_POSITION);
    }

}

////////////////////////////////////////////////////////////////////////////////////////
// setPosition
////////////////////////////////////////////////////////////////////////////////////////
void position::setPosition(position &otherPositionClass)
{
    *(this) = otherPositionClass;
}

////////////////////////////////////////////////////////////////////////////////////////
// setPosition
////////////////////////////////////////////////////////////////////////////////////////
void position::setPosition(std::vector<int> &otherPositionVector)
{
    positionVector=otherPositionVector;
}

////////////////////////////////////////////////////////////////////////////////////////
// moveRandom
////////////////////////////////////////////////////////////////////////////////////////
void position::moveRandom()
{
    int direction = getValueFromDistribution(DISTRIBUTION_DIRECTION);

    if(getValueFromDistribution(DISTRIBUTION_BINARY))
    {
        ++positionVector[direction];
        if( abs(positionVector[direction]+1) >= WORLD_SIZE )
        {
            positionVector[direction]= -WORLD_SIZE + 1;
        }
    }
    else
    {
        --positionVector[direction];
        if( abs(positionVector[direction]-1) >= WORLD_SIZE )
        {
            positionVector[direction]= WORLD_SIZE - 1;
        }
    }
}
