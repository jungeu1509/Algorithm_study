#include <iostream>
using namespace std;

unsigned int count[12];

int main(){
  int N, T;
  cin >> T;
  count[1] = 1; // 1
  count[2] = 2; // 1+1 2
  count[3] = 4; // 1+1+1 1+2 2+1 3

  for(int i = 4 ; i < 11 ; i++)
    count[i] = count[i-1] + count[i-2] + count[i-3];

  for(int i = 0 ; i < T; i++){
    cin >> N;
    cout << count[N] <<'\n';
  }

  return 0;
}
