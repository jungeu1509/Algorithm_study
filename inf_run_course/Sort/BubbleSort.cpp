#include <iostream>
#include "BubbleSort.h"
#include "ESort.h"
using namespace std;

void BubbleSort::Sort(int *data, int max_index) {
    ESort E;
    cout << "\n\nRun Bubble Sort\n\n"; 
    for(int i = 0; i < max_index ; i++) {
        int j;
        for(int j = 0; j < max_index - i - 1; j++) {
            if(data[j] > data[j+1])
                E.swap(&data[j], &data[j+1]);
        }
    }
}
