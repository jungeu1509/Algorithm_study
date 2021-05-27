#include <iostream>
using namespace std;

unsigned int data[12];

int myfunc(int A) {
    if(data[A] > 0) return data[A];
    data[A] = myfunc(A-1) + myfunc(A-2) + myfunc(A-3);
    return data[A];
}

int main(){
    int N, T;
    cin >> T;
    
    data[1] = 1; // 1
    data[2] = 2; // 1+1 2
    data[3] = 4; // 1+1+1 1+2 2+1 3
    
    for(int i = 0 ; i < T ; i++) {
        cin >> N;
        cout << myfunc(N) << '\n';
    }
    
    return 0;
}
