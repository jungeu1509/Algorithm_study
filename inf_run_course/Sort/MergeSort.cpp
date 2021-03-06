#include <iostream>
#include "MergeSort.h"
using namespace std;

void MergeSort::Sort(int *data, int max_index){
    cout << "\n\nRun Merge Sort\n\n";
    set_size(max_index);
    run(data, 0, max_index - 1);
    return;
}

/* Start margesort */
void MergeSort::run(int *data, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        run(data, start, mid);
        run(data, mid+1, end);
        merge(data, start, mid, end);
    }
}

void MergeSort::merge(int *data, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    int temp[get_size()] = {0, };

    /* Sorting */
    while(i <= mid && j <= end) {
        if(data[i] < data[j]){
            temp[k] = data[i];
            i += 1;
        }
        else {
            temp[k] = data[j];
            j += 1;
        }
        k += 1;
    }
    /* Remaining data processing */
    while(i <= mid) {
        temp[k] = data[i];
        i += 1;
        k += 1;
    }
    while(j <= end) {
        temp[k] = data[j];
        j += 1;
        k += 1;
    }

    /* Copy to original data */
    for(int l = start; l <= end ; l++) {
        data[l] = temp[l];
    }
}

/* Information hiding */
int MergeSort::get_size() {
    return max_size;
}

void MergeSort::set_size(int number) {
    max_size = number;
}
