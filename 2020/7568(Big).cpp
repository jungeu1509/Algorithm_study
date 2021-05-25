#include <iostream>
using namespace std;

typedef struct
{
    int x;
    int y;
}Info;

int main()
{
    Info person[200];
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> person[i].x >> person[i].y;
    for(int i = 0; i < N; i++)
    {
        int rank=0;
        for(int j = 0; j < N; j++)
            if((person[i].x < person[j].x) && (person[i].y < person[j].y))
                rank++;
        cout << rank + 1 << '\n';
    }

    return 0;
}
