#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int x;
    int y;
} Pair;

bool compare(Pair a, Pair b)
{
    if(a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Pair pair[100000];
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
        cin >>  pair[i].x >> pair[i].y;
    sort(pair, pair+N, compare);
    for(int i=0; i<N; i++)
        cout << pair[i].x << " " << pair[i].y << "\n";

    return 0;
}
