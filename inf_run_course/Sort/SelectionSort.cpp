#include <iostream>
#include "SelectionSort.h"
#include "ESort.h"
using namespace std;

void SelectionSort::Sort(int *data, int max_index){
    ESort E;
    cout << "\n\nRun Selection Sort\n\n";   
    for(int i = 0; i < max_index - 1 ; i++) {
        int max = 0;
        int j, index;
        for(j = 0; j < max_index - i ; j++) {
            if(data[j] > max) {
                max = data[j];
                index = j;
            }
        }
        E.swap(&data[index], &data[j-1]);
    }
}
