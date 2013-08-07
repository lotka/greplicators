#ifndef GENOME_H
#define GENOME_H

#include <unordered_map>

class genome
{
 public:
    typedef int allele;

    typedef allele genotype[2];

    typedef const char * genotypeName;

    float getSimilarity(genome &a, genome &b);

    genome combine(genome &a, genome &b);

    //Possibly allows for a risk of mutation whenever used
    int getGenotype(genotypeName &requestedName); /* This should return a probability possibly */

 protected:

    std::unordered_map<genotypeName, genotype> genomeMap;
};

class foodGenome : public genome
{
  static genotypeName maxFoodValue;
 public:
  foodGenome();
};

class animalGenome : public genome
{
 public:
  animalGenome();
};

#endif /* GENOME_H */
