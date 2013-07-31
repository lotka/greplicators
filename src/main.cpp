/*
TODO:
--Get rid of duplication of code for the age increment


*/


#include <iostream>
#include "entityCommon.h"
#include "animal.h"
#include "food.h"
#include "tools.h"

int main()
{
    //How long to run the simulation
    const int runLength = 200;
    bool status = false;

    //Create a set of entities
    entitySet mainEntitySet;

    //Populate the set
    status = generateEntities(mainEntitySet);
    if(status == false)
    {
        std::cout << "Failed to generate the starting eviorment and population" << std::endl;
        return false;
    }


      std::cout << "asda" << std::endl;

    //Enter main loop
    for(int i = 0; i < runLength; ++i)
    {
        //Preform operations on entities
        for(entitySet::iterator it = mainEntitySet.begin(); it != mainEntitySet.end(); it++)
        {
            //run the update function of each entity, passing copies of any entities that happen to occupy the same position
            (*it)->update(getCollidingEntities(it,mainEntitySet));
        }
    }

    return status;
}