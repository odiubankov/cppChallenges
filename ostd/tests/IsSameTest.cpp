#include "../IsSame.h"
#include <gtest/gtest.h>

namespace
{
class FirstType
{
};

class SecondType
{
};
}

namespace ostd
{

TEST(IsSame, test)
{
    bool isSame = IsSame<FirstType, FirstType>::Value;
    ASSERT_TRUE(isSame);
    isSame = IsSame<FirstType, SecondType>::Value;
    ASSERT_FALSE(isSame);
}

}//namespace ostd

