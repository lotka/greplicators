#include <map>

class genome
{
    typedef int allele;

    typedef allele genotype[2];

    typedef char * genotypeName;

    std::map<genotypeName, genotype> genomeMap;

public:

    genome();

    float getSimilarity(genome &a, genome &b);

    genome combine(genome &a, genome &b);

    int getAllele(genotypeName &requestedName); /* This should return a probability possibly */
};
