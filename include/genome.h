#ifndef GENOME_H
#define GENOME_H

#include <unordered_map>
    typedef int allele;
class genome
{
 public:


    typedef struct {
      allele dominant;
      allele recessive;
    } genotype;

    typedef const char * genotypeName;

    float getSimilarity(genome &a, genome &b);

    genome combine(genome &a, genome &b);

    //Possibly allows for a risk of mutation whenever used
    allele getGenotype(genotypeName &requestedName); /* Returns the dominant allele */

 protected:

    std::unordered_map<genotypeName, genotype> genomeMap;
};

class foodGenome : public genome
{
 public:
  static genotypeName maxFoodValue;
  foodGenome();
};

class animalGenome : public genome
{
 public:
  animalGenome();
};

#endif /* GENOME_H */
