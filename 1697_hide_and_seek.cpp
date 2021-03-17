#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K, Np, map[100001];
    queue <int> Q;
    for(int i = 0 ; i < 100001 ; i++) map[i] = -1;
    
    cin >> N >> K;
    Q.push(N);
    map[N] = 0;
    
    while(map[K] == -1) {
        Np = Q.front();
        Q.pop();
        
        if(Np-1 >= 0 && Np-1 <= 100000 && (map[Np-1] == -1)) {
            map[Np-1] = map[Np]+1;
            Q.push(Np-1);
        }
        
        if(Np+1 >= 0 && Np+1 <= 100000 && (map[Np+1] == -1)) {
            map[Np+1] = map[Np]+1;
            Q.push(Np+1);
        }
        
        if(Np*2 >= 0 && Np*2 <= 100000 && (map[Np*2] == -1)) {
            map[Np*2] = map[Np]+1;
            Q.push(Np*2);
        }
    }
    cout << map[K];
    return 0;
}
