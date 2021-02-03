#include <iostream>
#include <algorithm>
#include "ESort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main (void) {
    /* ----Choose sort algorithm---- */
    // SelectionSort Test;
    // BubbleSort Test;
    // InsertionSort Test;
    // MergeSort Test;
    QuickSort Test;

    ESort E;
    /* Original Data */
    int data[] = {-1, 0,9,4,7,2,1, -100};

    /* Copy the data to answer correct sort data */
    int data_size = sizeof(data)/sizeof(int);
    int data2[data_size] = {0,};

    for(int i = 0; i < data_size ; i++)
    {data2[i] = data[i];}

    /* Print rare data */
    cout << "rare data.\n";
    E.printData(data, data_size);

    /* Sort data */
    Test.Sort(data, data_size);

    /* Print sort data */
    cout << "sort data.\n";
    E.printData(data, data_size);

    /* Print correct data */
    cout << "answer data.\n";
    sort(data2, data2+data_size);
    E.printData(data2, data_size);

    return 0;
}
