#include "entityCommon.h"

////////////////////////////////////////////////////////////////////////////////////////
// render
////////////////////////////////////////////////////////////////////////////////////////
void entity::render()
{

}

////////////////////////////////////////////////////////////////////////////////////////
// constructor
////////////////////////////////////////////////////////////////////////////////////////
int entity::comparePositionWith(entity &other)
{
    position thisEntityPosition = this->currentPosition;
    position otherPosition = other.getPosition();

    //Return false if just any pair of coordinates are different
    for(int i = 0; i < SPACE_DIMENSIONS; ++i)
    {
        if(thisEntityPosition[i] != otherPosition[i])
        {
            return false;
        }
    }

    return true;
}

////////////////////////////////////////////////
// getPosition
////////////////////////////////////////////////
position entity::getPosition()
{
    return this->currentPosition;
}

genome::genome()
{

}