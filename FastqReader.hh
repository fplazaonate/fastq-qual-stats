#ifndef FASTQ_READER_HH
#define FASTQ_READER_HH

#include <string>
#include <fstream>
#include "FastqSequence.hh"

class FastqReader
{
    public:
        FastqReader(const std::string& filepath);
        ~FastqReader();
        bool next_sequence(FastqSequence& fastq_seq);

    private:
        const std::string filepath_;
        std::ifstream filestream_;
        std::string line_;
};

#endif // FASTQ_READER_HH
