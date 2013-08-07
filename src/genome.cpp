#include "genome.h"

genome::genotypeName foodGenome::maxFoodValue = "maxFoodValue";

foodGenome::foodGenome()
{
  genotypeName test = "test";
  genotype a;
  a[0]=10;
  a[1]=4;
  genomeMap[test]=a;
}
