
#ifndef MEYERSEXAMPLES_POORPIGS_H
#define MEYERSEXAMPLES_POORPIGS_H

#include <iostream>
#include <cmath>

using namespace std;

namespace poorpigs {

    unsigned power( unsigned val, unsigned pow )
    {
        if ( pow == 0 )
        {
            return 1;
        }

        return val * power(val, pow - 1);
    }

    class Solution
    {
    public:
        int poorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            auto attemptsCnt = static_cast<unsigned >(minutesToTest / minutesToDie);
            for (auto i = 1u;; ++i)
            {
                if (buckets <= power(attemptsCnt + 1, i))
                    return i;
            }
        }
    };
};


#endif //MEYERSEXAMPLES_POORPIGS_H
