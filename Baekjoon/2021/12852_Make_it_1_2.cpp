#include <iostream>
using namespace std;

#define MAX_NUM 1000002

int count_data[MAX_NUM];
int root_data[MAX_NUM];

void calc(int A) {
    int i = 1;
    while(i < A) {
        if((i+1 < MAX_NUM) && ((count_data[i+1] == 0) ||(count_data[i+1] > count_data[i] + 1))) {
            count_data[i+1] = count_data[i]+1;
            root_data[i+1] = i;
        }
        
        if((i*2 < MAX_NUM) && ((count_data[i*2] == 0) ||(count_data[i*2] > count_data[i] + 1))) {
            count_data[i*2] = count_data[i] + 1;
            root_data[i*2] = i;
        }
        
        if((i*3 < MAX_NUM) && ((count_data[i*3] == 0) ||(count_data[i*3] > count_data[i] + 1))) {
            count_data[i*3] = count_data[i] + 1;
            root_data[i*3] = i;
        }
        i++;
    }
}

void printRoot(int A) {
    cout << A << " ";
    if(A > 1) {
        printRoot(root_data[A]);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    
    count_data[1] = 1;
    root_data[1] = 1;
    
    calc(N);
    cout << count_data[N]-1 << '\n';
    printRoot(N);
    
    return 0;
}
