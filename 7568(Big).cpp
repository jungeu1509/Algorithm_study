#include <iostream>
using namespace std;

typedef struct
{
    int x;
    int y;
    int rank;
}Info;

int main()
{
    Info person[200] = {0, };
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> person[i].x >> person[i].y;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            if((person[i].x < person[j].x) && (person[i].y < person[j].y))
                person[i].rank++;
        cout << person[i].rank + 1 << '\n';
    }

    return 0;
}
