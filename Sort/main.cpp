#include <iostream>
#include <algorithm>
#include "ESort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main (void) {
    /* ----Choose sort algorithm---- */
    /* SelectionSort Test; */
    /* BubbleSort Test; */
    /* InsertionSort Test; */
    MergeSort Test;

    ESort E;
    int data[] = {-1, 0,9,4,7,2,1, -100};
    int data_size = sizeof(data)/sizeof(int);
    int data2[data_size] = {0,};

    for(int i = 0; i < data_size ; i++)
    {data2[i] = data[i];}

    cout << "rare data.\n";
    E.printData(data, data_size);

    Test.Sort(data, data_size);

    cout << "sort data.\n";
    E.printData(data, data_size);
    cout << "answer data.\n";
    sort(data2, data2+data_size);
    E.printData(data2, data_size);

    return 0;
}
