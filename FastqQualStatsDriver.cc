#include "FastqQualStatsDriver.hh"
#include "FastqMultiReader.hh"
#include "Matrix.hh"
#include "FastqQualAnalyzer.hh"
#include "FastqQualStatsPrinter.hh"

void FastqQualStatsDriver::run_analysis(const std::vector<std::string>& fastq_files, const std::string& stats_file)
{
    FastqMultiReader reader(fastq_files);

    FastqQualAnalyzer analyzer;
    std::vector<FastqEntry> fastq_entries;

    while(reader.next_chunk(fastq_entries))
    {
        analyzer.analyze(fastq_entries);
    }

    const Matrix<boost::uint64_t>& quals_counts = analyzer.get_quals_counts();
    FastqQualStatsPrinter::print(quals_counts, stats_file);
}

