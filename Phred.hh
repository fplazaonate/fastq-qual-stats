#ifndef PHRED_HPP
#define PHRED_HPP

#include <cstddef>

class Phred
{
    public:
        static const size_t NUM_QUALS = 42;
        static size_t decode_phred_33(const unsigned char c);
        static const char* encode_phred33(const size_t q);

    private:
        static const size_t decode_phred33_lut[128];
        static const char* encode_phred33_lut[NUM_QUALS+1];
};

inline size_t Phred::decode_phred_33(const unsigned char c)
{
    return decode_phred33_lut[c];
}

inline const char* Phred::encode_phred33(const size_t q)
{
    return (q >= NUM_QUALS) ? encode_phred33_lut[NUM_QUALS] : encode_phred33_lut[q];
}

#endif // PHRED_HPP

