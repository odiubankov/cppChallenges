#include "../Vector.h"
#include <gtest/gtest.h>

namespace ostd
{

TEST(Vector, push_back)
{
    Vector<int> vInt;
    ASSERT_EQ(vInt.size(), 0);
    vInt.push_back(10);
    ASSERT_EQ(vInt.size(), 1);
}

TEST(Vector, push_back100)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    ASSERT_EQ(vInt.size(), 100);
}

TEST(Vector, pop_back100x2)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    for (int i = 0; i < 100; ++i) {
        vInt.pop_back();
    }

    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    for (int i = 0; i < 100; ++i) {
        vInt.pop_back();
    }

    ASSERT_EQ(vInt.size(), 0);
}

TEST(Vector, operator_brackets)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    for (int i = 0; i < 100; ++i) {
        vInt[i] = 10 * i;
    }

    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(vInt[i], 10 * i);
    }
}

TEST(Vector, copy_constructor)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    Vector<int> vInt2{vInt};
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(vInt[i], i);
        ASSERT_EQ(vInt2[i], i);
    }
}

TEST(Vector, copy_assignment)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    Vector<int> vInt2;
    vInt2 = vInt;
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(vInt[i], i);
        ASSERT_EQ(vInt2[i], i);
    }
}

TEST(Vector, move_constructor)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    Vector<int> vInt2{std::move(vInt)};
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(vInt2[i], i);
    }

    ASSERT_EQ(vInt.size(), 0);
}

TEST(Vector, move_assignment)
{
    Vector<int> vInt;
    for (int i = 0; i < 100; ++i) {
        vInt.push_back(i);
    }

    Vector<int> vInt2;
    vInt2 = std::move(vInt);
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(vInt2[i], i);
    }

    ASSERT_EQ(vInt.size(), 0);
}

}//namespace ostd
