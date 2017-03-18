#include "./UnivRefOverload.h"

#include <iostream>

namespace item27{

    Base::Base(int, int)
    {
        std::cout << "B int" << std::endl;
    }


    Base::Base(std::string)
    {
        std::cout << "B string" << std::endl;
    }


    void test()
    {
        Derived derived(int{}, int{});
        auto derivedCopy { derived };
    }

}//namespace item27