#include "entityCommon.h"
#include "../tools.h"

////////////////////////////////////////////////////////////////////////////////////////
// constructor
////////////////////////////////////////////////////////////////////////////////////////
position::position()
{
    positionVector.resize(SPACE_DIMENSIONS);
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
    int direction = getValueFromDistribution(DISTRIBUTION_POSITION);

    if(getValueFromDistribution(DISTRIBUTION_BINARY))
    {
        //std::cout << "Move forward" << std::endl;
        if( abs(positionVector[direction]+1) == WORLD_SIZE )
        {
            positionVector[direction]= -WORLD_SIZE + 1;
        }
        else
        {
            ++positionVector[direction];
        }
    }
    else
    {
        //std::cout << "Move backwards" << std::endl;
        if( abs(positionVector[direction]-1) == WORLD_SIZE )
        {
            positionVector[direction]= WORLD_SIZE - 1;
        }
        else
        {
            --positionVector[direction];
        }
    }
}
