#ifndef FASTQ_QUAL_ANALYZER_HH
#define FASTQ_QUAL_ANALYZER_HH

#include <vector>
#include <boost/cstdint.hpp>
#include "FastqEntry.hh"
#include "Matrix.hh"

class FastqQualAnalyzer
{
    public:
        FastqQualAnalyzer();
        ~FastqQualAnalyzer();
        void analyze(const std::vector<FastqEntry>& entries);
        const Matrix<boost::uint64_t>& get_quals_counts() const;

    private:
        Matrix<boost::uint64_t> quals_counts_;
};


inline const Matrix<boost::uint64_t>& FastqQualAnalyzer::get_quals_counts() const
{
    return quals_counts_;
}

#endif
