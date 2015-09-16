#ifndef MATRIX_HH
#define MATRIX_HH

#include <cstddef>

template <typename T>
class Matrix
{
    public:
        Matrix(const size_t nrow, const size_t ncol);
        ~Matrix();
        size_t nrow() const;
        size_t ncol() const;
        size_t offset(const size_t i, const size_t j)const ;
        T operator()(const size_t i, const size_t j) const;
        T& operator()(const size_t i, const size_t j);
    private:
        const size_t nrow_;
        const size_t ncol_;
        T* data_;
};

template <typename T>
inline Matrix<T>::Matrix(const size_t nrow, const size_t ncol)
    : nrow_(nrow), ncol_(ncol), data_(new T[nrow_*ncol_])
{
}

template <typename T>
inline Matrix<T>::~Matrix()
{
    delete[] data_;
}

template <typename T>
inline size_t Matrix<T>::nrow() const
{
    return nrow_;
}

template <typename T>
inline size_t Matrix<T>::ncol() const
{
    return ncol_;
}

template <typename T>
inline size_t Matrix<T>::offset(const size_t i, const size_t j) const 
{
    return i*ncol_+j;
}

template <typename T>
T Matrix<T>::operator()(const size_t i, const size_t j) const
{
    return data_[offset(i,j)];
}

template <typename T>
T& Matrix<T>::operator()(const size_t i, const size_t j)
{
    return data_[offset(i,j)];
}

#endif // MATRIX_HH
