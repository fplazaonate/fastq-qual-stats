#ifndef PHRED_HPP
#define PHRED_HPP

#include <cstddef>

class Phred
{
    public:
        size_t decode_phred_33(const unsigned char c);

    private:
        static const size_t decode_phred33_lut[128];
};

inline size_t Phred::decode_phred_33(const unsigned char c)
{
    return decode_phred33_lut[c];
}

#endif // PHRED_HPP

