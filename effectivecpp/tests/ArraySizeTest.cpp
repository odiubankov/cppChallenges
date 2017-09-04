#include "../ArraySize.h"
#include <gtest/gtest.h>

namespace effectivecpp
{

TEST(ArraySize, test)
{
    int testArray[10];
    ASSERT_EQ(effectivecpp::arraySize(testArray), 10);
}

}//namespace effectivecpp