#include "InsertInMap.h"

#include <map>
#include <vector>
#include <iostream>

class A
{
public:
    A() { std::cout << "Default constr" << std::endl; }
    A(const A&) { std::cout << "Copy constr" << std::endl; }
    ~A() { std::cout << "destr" << std::endl; }
    A(A&&){ std::cout << "Move constr" << std::endl; }
    A& operator=(const A&) { std::cout << "assignment" << std::endl; return *this; }
    A& operator=(const A&&) { std::cout << "move assignment" << std::endl; return *this; }
};


namespace insertinmap {
    void testNotOptimized()
    {
        std::map<int, std::vector<A>> mapIntVector;

    }
}
