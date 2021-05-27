#include <iostream>
#include "Heapsort.h"
#include "ESort.h"
using namespace std;

void HeapSort::Sort(int *data, int max_index){
    ESort E;
    cout << "\n\nRun Heap Sort\n\n";
    
    for(int i = max_index ; i > 0; i--){
        Build_Max_Heap(data, i);
        E.swap(&data[0], &data[i-1]);
    }
    return;
}

void HeapSort::Build_Max_Heap(int *data, int max_index) {
    set_size(max_index);
    for(int i = (get_size()/2) ; i > 0 ; i--){
        Max_Heapify(data, i-1);
    }
}

void HeapSort::Max_Heapify(int*data, int node){
    ESort E;
    int leaf = node * 2;

    /* none leaf node */
    if(leaf > get_size()-1)
        return;

    /* have only leaf node */
    if(leaf+1 > get_size()-1){
        if(data[node] < data[leaf]) {
            E.swap(&data[leaf], &data[node]);
        }
        return;
    }

    /* have two leaf node */
    if(data[leaf] > data[leaf+1]){
        if(data[node] < data[leaf]) {
            E.swap(&data[node], &data[leaf]);
            Max_Heapify(data, leaf);
        }
    }
    else {
        if(data[node] < data[leaf+1]) {
            E.swap(&data[node], &data[leaf+1]);
            Max_Heapify(data, leaf+1);
        }
    }
    return;
}

/* Information hiding */
int HeapSort::get_size() {
    return max_size;
}

void HeapSort::set_size(int number) {
    max_size = number;
}
