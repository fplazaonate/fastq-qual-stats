#ifndef FASTQ_QUAL_STATS_PRINTER_HH
#define FASTQ_QUAL_STATS_PRINTER_HH

#include <string>
#include "Matrix.hh"
#include <boost/cstdint.hpp>

class FastqQualStatsPrinter
{
    public:
        static void print(const Matrix<boost::uint64_t>& quals_counts, const std::string& stats_file);
};

#endif // FASTQ_QUAL_STATS_PRINTER_HH
