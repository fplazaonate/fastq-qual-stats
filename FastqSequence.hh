#ifndef FASTQ_SEQUENCE_HH
#define FASTQ_SEQUENCE_HH

#include <string>
#include <iostream>

struct FastqSequence
{
    std::string id;
    std::string seq;
    std::string quals;
};

std::ostream& operator<<(std::ostream& os, const FastqSequence& fastq_sequence);

#endif //FASTQ_SEQUENCE_HH
