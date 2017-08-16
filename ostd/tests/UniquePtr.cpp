#include "../UniquePtr.h"
#include <gtest/gtest.h>

namespace
{
static const int CONST_METHOD_VAL = 0;

static const int NON_CONST_METHOD_VAL = 1;
}

class TestOwnership
{
public:
    TestOwnership(int &ownershipCounter)
        : _ownershipCounter{ownershipCounter}
    {
        ++_ownershipCounter;
    }

    ~TestOwnership()
    {
        --_ownershipCounter;
    }

    int getCounterVal() const
    { return _ownershipCounter; }

    int constCheckMethod() const
    { return CONST_METHOD_VAL; }

    int constCheckMethod()
    { return NON_CONST_METHOD_VAL; }

private:
    int &_ownershipCounter;
};

namespace ostd
{

TEST(UniquePtr, ownership)
{
    int counter = 0;
    {
        UniquePtr<TestOwnership> ptr{new TestOwnership(counter)};
    }

    ASSERT_EQ(counter, 0);
}

TEST(UniquePtr, defaultConstruct)
{
    UniquePtr<TestOwnership> ptr;
    ASSERT_EQ(nullptr, ptr.get());
}

TEST(UniquePtr, moveConstruct)
{
    int counter = 0;
    UniquePtr<TestOwnership> ptr1{new TestOwnership(counter)};
    UniquePtr<TestOwnership> ptr2{std::move(ptr1)};
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}

TEST(UniquePtr, moveAssignment)
{
    int counter = 0;
    UniquePtr<TestOwnership> ptr1{new TestOwnership(counter)};
    UniquePtr<TestOwnership> ptr2;
    ptr2 = std::move(ptr1);
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}

TEST(UniquePtr, testPolicies)
{
    ASSERT_FALSE(std::is_copy_constructible<UniquePtr<int>>::value);
    ASSERT_FALSE(std::is_copy_assignable<UniquePtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_constructible<UniquePtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_assignable<UniquePtr<int>>::value);
}

TEST(UniquePtr, operatorArrow)
{
    int counterVal = 0;
    UniquePtr<TestOwnership> uniquePtr{new TestOwnership(counterVal)};
    ASSERT_EQ(uniquePtr->getCounterVal(), 1);
}

TEST(UniquePtr, operatorDereferenceNonConst)
{
    int counterVal = 0;
    UniquePtr<TestOwnership> uniquePtr{new TestOwnership(counterVal)};
    ASSERT_EQ((*uniquePtr).constCheckMethod(), NON_CONST_METHOD_VAL);
}

TEST(UniquePtr, operatorDereferenceConst)
{
    int counterVal = 0;
    UniquePtr<TestOwnership> uniquePtr{new TestOwnership(counterVal)};
    const auto &constRef = uniquePtr;
    ASSERT_EQ((*constRef).constCheckMethod(), CONST_METHOD_VAL);
}

}//namespace ostd


