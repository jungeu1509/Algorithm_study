#include <iostream>
#include "InsertionSort.h"
using namespace std;

void InsertionSort::Sort(int *data, int max_index) {
    cout << "\n\nRun Insert Sort\n";
    for(int i = 1; i< max_index ; i++) {
        int max = 0;
        int temp = data[i];
        for(int j = i - 1; j >= 0; j--) {
            if(data[j] > temp) {
                data[j+1] = data[j];
                if(j == 0){data[j] = temp; break;}
            }
            else {
                data[j+1] = temp;
                break;
            }
        }
    }
}
