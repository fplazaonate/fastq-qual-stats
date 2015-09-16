#ifndef FASTQ_QUAL_DRIVER_DRIVER_HH
#define FASTQ_QUAL_DRIVER_DRIVER_HH

#include <vector>
#include <string>

class FastqQualStatsDriver
{
    public:
        static void run_analysis(const std::vector<std::string>& fastq_files, const std::string& stats_file);
};


#endif // FASTQ_QUAL_DRIVER_DRIVER_HH
