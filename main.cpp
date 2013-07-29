/*
TODO:
--Get rid of duplication of code for the age increment


*/


#include <iostream>
#include "entities/entityCommon.h"
#include "entities/animal.h"
#include "entities/food.h"
#include "tools.h"

int main()
{

    std::ofstream logReport;

    logReport.open("logFile.txt");

    //How long to run the simulation
    const int runLength = 20;
    bool status = false;

    //Create a set of entities
    entitySet mainEntitySet;

    LOGREPORT("Brains" << "Zombies");

    //Populate the set
    status = generateEntities(mainEntitySet);
    if(status == false)
    {
        std::cout << "Failed to generate the starting eviorment and population" << std::endl;
        return false;
    }

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

    logReport.close();

    return status;

}
