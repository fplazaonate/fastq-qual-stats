#include "FastqSequence.hh"

std::ostream& operator<<(std::ostream& os, const FastqSequence& fastq_sequence)
{
    os << '@' << fastq_sequence.id << '\n';
    os << fastq_sequence.seq << '\n';
    os << "+\n";
    os << fastq_sequence.quals << '\n';

    return os;
}
