#include <iostream>
#include <queue>
#include "entityCommon.h"
#include "animal.h"
#include "food.h"
#include "tools.h"

int main()
{
    //How long to run the simulation
    const int runLength = 200;
    bool status = false;

    //Initial conditions
    double animalDensity = 0.2;
    double foodDensity = 1;

    //Create a set of entities
    entitySet mainEntitySet;

    //Populate the set
    status = generateEntities(mainEntitySet,animalDensity,foodDensity);
    if(status == false)
    {
        std::cout << "Failed to generate the starting eviorment and population" << std::endl;
        return status;
    }

    //Enter main loop
    for(int i = 0; i < runLength; ++i)
    {
        //Preform operations on entities
        for(entitySet::iterator it = mainEntitySet.begin(); it != mainEntitySet.end(); it++)
        {
          //delete the entity if it has expired
	  if( ! ( (*it)->alive() ) )
            {
	        //Temporary pointer to deletion target
      	        delete *it;
		mainEntitySet.erase(it);
                --it;
                continue;
            }

            //run the update function of each entity
	    //passing a set of pointers to colliding objects
            (*it)->update( getCollidingEntities( it , mainEntitySet ) );
        }
    }

    std::cout << "##Final Stats##" << std::endl << "Objects still alive: " << mainEntitySet.size();
    std::cout << " after: " << runLength << " turns." << std::endl;

    return status;
}
