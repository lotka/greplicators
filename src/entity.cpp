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
// alive
////////////////////////////////////////////////
bool entity::alive()
{
  if( hp < 1 )
  {
    //Dead (So that main.cpp knows to remove it from the list)
    std::cout << "hp < 1" << std::endl;
    return false;
  }
  else
  {
      //Still alive
      return true;
  }

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
