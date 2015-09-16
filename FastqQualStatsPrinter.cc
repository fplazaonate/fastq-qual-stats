#include "FastqQualStatsPrinter.hh"
#include <fstream>
#include "Phred.hh"

void FastqQualStatsPrinter::print(const Matrix<boost::uint64_t>& quals_counts, const std::string& stats_file)
{
    std::ofstream ofs;
    ofs.open(stats_file.c_str());

    // Matrix is transposed for readability purposes
    const size_t num_quals = quals_counts.ncol();
    const size_t num_pos = quals_counts.nrow();

    // Print header
    ofs << "qual_int" << '\t' << "qual_chr"; 
    for (size_t pos = 1; pos <= num_pos; ++pos)
    {
        ofs << '\t' << "pos" << pos;
    }
    ofs << '\n';


    // Print quals counts
    for (size_t qual = 0; qual < num_quals; ++qual)
    {
        ofs << qual << '\t' << Phred::encode_phred33(qual);
        for (size_t pos = 0; pos < num_pos; ++pos)
        {
            ofs << '\t' << quals_counts(pos, qual);
        }
        ofs << '\n';
    }


    ofs.close();
}
