#ifndef FASTQ_SEQUENCE_HH
#define FASTQ_SEQUENCE_HH

#include <string>
#include <iostream>

struct FastqEntry
{
    std::string id;
    std::string seq;
    std::string quals;
};

std::ostream& operator<<(std::ostream& os, const FastqEntry& fastq_entry);

#endif //FASTQ_SEQUENCE_HH
