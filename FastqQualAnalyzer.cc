#include "FastqQualAnalyzer.hh"
#include <iostream>
#include <boost/foreach.hpp>
#include "FastqEntry.hh"
#include "Phred.hh"

FastqQualAnalyzer::FastqQualAnalyzer()
    : quals_counts_(FastqEntry::MAX_SEQ_LEN, Phred::NUM_QUALS+1)
{
}

FastqQualAnalyzer::~FastqQualAnalyzer()
{
}


void FastqQualAnalyzer::analyze(const std::vector<FastqEntry>& entries)
{
    BOOST_FOREACH(const FastqEntry& entry, entries)
    {
        const std::string& quals = entry.quals;
        for (size_t pos = 0; pos < quals.size(); ++pos)
        {
            const size_t qual = Phred::decode_phred_33(quals[pos]);
            quals_counts_(pos,qual)++;

            // Check if qual value is valid
            if (qual == Phred::NUM_QUALS)
            {
                std::cerr << "warning: invalid Phred quality '" << quals[pos] << 
                    "' in read '" << entry.id << "' at position " << pos+1 << std::endl;
            }
        }
    }
}

