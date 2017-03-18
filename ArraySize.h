#ifndef MEYERSEXAMPLES_ARRAYSIZE_H
#define MEYERSEXAMPLES_ARRAYSIZE_H

#include <iostream>

namespace item1{
    template<typename T, std::size_t  N>
    constexpr std::size_t arraySize(T (&)[N])noexcept
    {
        return N;
    }

    void test();
}


#endif //MEYERSEXAMPLES_ARRAYSIZE_H
