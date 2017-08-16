#include "../Distance.h"
#include <gtest/gtest.h>
#include <list>


namespace ostd
{

TEST(Distance, test)
{
    std::vector<int> v{1, 2, 3};
    ASSERT_EQ(ostd::Distance(std::begin(v), std::end(v)), v.size());

    std::list<int> l{1, 2};
    ASSERT_EQ(ostd::Distance(std::begin(l), std::end(l)), l.size());
}


}//namespace ostd
