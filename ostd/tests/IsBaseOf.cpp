#include "../IsBaseOf.h"
#include <gtest/gtest.h>

namespace
{
class TrueBase
{
};

class FalseBase
{
};

class Derived: public TrueBase
{
};
}

namespace ostd
{

TEST(IsBaseOf, test)
{
    bool isBase = ostd::IsBaseOf<Derived, TrueBase>::Value;
    ASSERT_TRUE(isBase);
    isBase = ostd::IsBaseOf<Derived, FalseBase>::Value;
    ASSERT_FALSE(isBase);
}

}//namespace ostd
