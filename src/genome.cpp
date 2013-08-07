#include "genome.h"
#include "tools.h"

/*! Sets the maximum food value
 *  INITIIAL MAX  = 10000
 *  INITIAL MIN   = 0
 */
genome::genotypeName foodGenome::maxFoodValue = "maxFoodValue";

foodGenome::foodGenome()
{
  genotype randomGenotype;
  randomGenotype.dominant = getValueFromDistribution(DISTRIBUTION_GENOME);
  randomGenotype.recessive =  getValueFromDistribution(DISTRIBUTION_GENOME);
  genomeMap[maxFoodValue] = randomGenotype;
}

allele genome::getGenotype(genotypeName &requestedName)
{
  return genomeMap[requestedName].dominant; 
}
