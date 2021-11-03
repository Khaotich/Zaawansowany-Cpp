#ifndef WEKTOR_HPP
#define WEKTOR_HPP


#include <iostream>

using namespace std;

//zadanie 3
template <typename T, int size, T value = 0.0>
class Wektor
{
    T array_[size];
    int size_;

public:
    Wektor()
    {
        for (int i = 0; i < size; ++i) array_[i] = value;
        size_ = size;
    }

    int len() const
    {
        return size_;
    }

    T& operator[](int index)
    {
        return array_[index];
    }

    T operator[](int index) const
    {
        return array_[index];
    }

    using value_type = T;
};

#endif // WEKTOR_HPP