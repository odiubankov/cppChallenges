#include "../UnivRefOverload.h"
#include <gtest/gtest.h>

namespace effectivecpp
{

TEST(UnivRefOverload, forwardConstructorIsCalled)
{
    DerivedSFINAE derived(int
    {}, int{});
    ASSERT_TRUE(derived._forwardConstructorIsCalled);
}

TEST(UnivRefOverload, defaultCopyConstructorIsCalled)
{
    DerivedSFINAE derived(int
    {}, int{});
    derived._forwardConstructorIsCalled = false;

    DerivedSFINAE derivedCopy{derived};

    ASSERT_TRUE(!derivedCopy._forwardConstructorIsCalled);
}

}//namespace effectivecpp