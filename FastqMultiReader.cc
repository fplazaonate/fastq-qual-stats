#include "FastqMultiReader.hh"

FastqMultiReader::FastqMultiReader(const std::vector<std::string>& fastq_files)
    : fastq_files_(fastq_files), cur_fastq_file_(fastq_files_.begin()), cur_fastq_reader_(NULL)
{
    if (cur_fastq_file_ != fastq_files_.end())
    {
        cur_fastq_reader_ = std::auto_ptr<FastqReader>(new FastqReader(*cur_fastq_file_));
    }
}

bool FastqMultiReader::next_chunk(std::vector<FastqEntry>& fastq_entries, const size_t chunk_size)
{
    FastqEntry fastq_entry;
    fastq_entries.clear();
    fastq_entries.reserve(chunk_size);

    while (cur_fastq_file_ != fastq_files_.end())
    {
        while (fastq_entries.size() < chunk_size && cur_fastq_reader_->next_entry(fastq_entry))
        {
            fastq_entries.push_back(fastq_entry);
        }

        if (fastq_entries.size() < chunk_size)
        {
            ++cur_fastq_file_;

            if (cur_fastq_file_ != fastq_files_.end())
            {
                cur_fastq_reader_ = std::auto_ptr<FastqReader>(new FastqReader(*cur_fastq_file_));
            }
        }
        else
        {
            break;
        }
    }

    if (fastq_entries.empty())
        return false;

    return true;
}
