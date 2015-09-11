#include "FastqReader.hh"

FastqReader::FastqReader(const std::string& filepath)
    : filepath_(filepath), filestream_(filepath_.c_str(), std::ios_base::in), line_()
{
    line_.reserve(10000);
}

FastqReader::~FastqReader()
{
    filestream_.close();
}

bool FastqReader::next_sequence(FastqSequence& fastq_seq)
{
    if (!filestream_.good())
    {
        return false;
    }

    std::getline(filestream_, line_);
    if (line_.empty())
    {
        // Sometimes FASTQ files have empty last line_s
        filestream_.setstate(std::ios::eofbit);  
        return false;
    }

    if (line_[0] != '@')
    {
        // TODO: had error msg
        filestream_.setstate(std::ios::failbit);  
        return false;
    }
    fastq_seq.id = line_.substr(1);

    std::getline(filestream_, line_);
    if (line_.empty() || line_[0] != '+') 
    {
        // TODO: had error msg
        filestream_.setstate(std::ios::failbit);  
        return false;
    }

    std::getline(filestream_, fastq_seq.quals);
    if (fastq_seq.quals.empty()) 
    {
        // TODO: had error msg
        filestream_.setstate(std::ios::failbit);  
        return false;
    }
    return true;
}
