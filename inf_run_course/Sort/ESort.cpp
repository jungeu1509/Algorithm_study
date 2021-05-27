#include <iostream>
#include "ESort.h"

void ESort::swap (int *A, int*B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

void ESort::printData(int *data, int max_index) {
    for(int i = 0 ; i < max_index ; i++)
        std::cout << data[i] << '\t';
    std::cout << '\n';
}
