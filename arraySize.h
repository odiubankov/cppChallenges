//
// Created by Oleksii Diubankov on 12/02/2017.
//

#ifndef MEYERSEXAMPLES_ARRAYSIZE_H
#define MEYERSEXAMPLES_ARRAYSIZE_H

#include <cstdio>

template<typename T, std::size_t  N>
constexpr std::size_t arraySize(T (&)[N])noexcept
{
    return N;
}

#endif //MEYERSEXAMPLES_ARRAYSIZE_H
