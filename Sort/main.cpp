#include <iostream>
#include <algorithm>
#include "ESort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"

using namespace std;

int main (void) {
    /* Choose sort algorithm */
    /* SelectionSort Test; */
    /* BubbleSort Test; */
    InsertionSort Test;

    ESort E;
    int data[] = {-100,-1, 0,9,4,7,2,1};
    int data_size = sizeof(data)/sizeof(int);

    cout << "rare data.\n";
    E.printData(data, data_size);

    Test.Sort(data, data_size);

    cout << "sort data.\n";
    E.printData(data, data_size);
    cout << "answer data.\n";
    sort(data, data+data_size);
    E.printData(data, data_size);

    return 0;
}
