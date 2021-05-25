#include <iostream>
using namespace std;

unsigned int count[1000001];

unsigned int func(int a) {
    unsigned int ret = 1000001;
    unsigned int temp;

    if(a <= 1) return 0;
    if(count[a] > 0) return count[a];

    if(a % 3 == 0) ret = func(a/3);
    if(a % 2 == 0) {
      temp = func(a/2);
      if(ret > temp) ret = temp;
    }

    temp = func(a-1);
    if(ret > temp){
      ret = temp;
    }

    count[a] = ret + 1;
    return count[a];
}

int main(){
    int N;
    cin >> N;
    cout << func(N) << '\n';
    return 0;
}
