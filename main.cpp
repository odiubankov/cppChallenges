#include <iostream>
#include "arraySize.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto uniqueInt = std::make_unique<int>(10);

    int testArray[10];
    std::cout << arraySize(testArray) << std::endl;
    return 0;
}