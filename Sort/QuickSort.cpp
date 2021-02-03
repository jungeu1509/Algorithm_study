#include <iostream>
#include "QuickSort.h"
#include "ESort.h"
using namespace std;

void QuickSort::Sort(int *data, int max_index){
    cout << "\n\nRun Quick Sort\n\n";
    run(data, 0, max_index -1);
    return;
}

void QuickSort::run(int *data, int start, int end) {
    if(start < end) {
        int mid = partition(data, start, end);
        run(data, start, mid-1);
        run(data, mid + 1, end);
    }
}

int QuickSort::partition(int *data, int start, int end) {
    ESort E;
    int pivot = data[end];
    int i = start - 1;
    for(int j = start ; j < end ; j++) {
        if(data[j] <= pivot) {
            i += 1;
            E.swap(&data[i], &data[j]);
        }
    }
    E.swap(&data[i+1], &data[end]);
    return i + 1;
}
