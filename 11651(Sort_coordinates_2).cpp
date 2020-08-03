#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int x;
    int y;
}location;

bool compare(location a, location b)
{
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main()
{
    int N;
    location loc[100000];
    
    cin >> N;
    
    for(int i = 0; i < N ; i++)
        cin >> loc[i].x >> loc[i].y;
    
    sort(loc, loc + N, compare);
    
    for(int i = 0 ; i < N ; i++)
        cout << loc[i].x << " " << loc[i].y << '\n';
        
    return 0;
}
