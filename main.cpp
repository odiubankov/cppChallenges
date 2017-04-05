#include "ArraySize.h"
#include "UnivRefOverload.h"
#include "InsertInMap.h"
#include "PoorPigs.h"

#include <iostream>

using namespace std;

int main()
{
//    item1::test();
//    item27::test();
//    insertinmap::test();
    poorpigs::Solution poorPigs;
    int result = poorPigs.poorPigs(1000, 15, 60);
    cout << result << endl;
    result = poorPigs.poorPigs(1000, 12, 60);
    cout << result << endl;
    return 0;
}