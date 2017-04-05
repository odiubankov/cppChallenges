
#ifndef MEYERSEXAMPLES_POORPIGS_H
#define MEYERSEXAMPLES_POORPIGS_H


namespace poorpigs {

    class Solution {
    public:
        int poorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            if (buckets == 1)
            {
                return 0;
            }

            for (int pigsCnt = 1;; ++pigsCnt)
            {
                int actualPigsCnt = pigsCnt;
                int bucketsLeft = buckets;
                for (int i = 1; i * minutesToDie <= minutesToTest && actualPigsCnt > 0; ++i, --actualPigsCnt)
                {
                    int newBucketsCnt = bucketsLeft / (actualPigsCnt + 1);
                    if (bucketsLeft % (actualPigsCnt + 1) != 0)
                    {
                        ++newBucketsCnt;
                    }

                    bucketsLeft = newBucketsCnt;
                }

                if ((bucketsLeft - 2) <= actualPigsCnt)
                {
                    return pigsCnt;
                }
            }
        }
    };
};


#endif //MEYERSEXAMPLES_POORPIGS_H
