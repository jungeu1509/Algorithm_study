#include <iostream>
using namespace std;

#define MAX_NUMBER 1001
typedef struct _List
{
    int number;
    _List *next;
}List;

int main()
{
    int N, K, i, count;
    List *cur_data, *past_data;
    List list[MAX_NUMBER];
    cin >> N >> K;
    for(i=1; i<=N; i++)
    {
        list[i].number = i;
        list[i].next = &list[(i % N) + 1];
    }
    past_data = &list[--i];
    cur_data = &list[1];
    count = 1;
    cout << "<";
    while(i > 0)
    {
        if(count == K)
        {
            count = 1;
            i--;
            cout << cur_data->number;
            past_data->next = cur_data->next;
            cur_data = cur_data->next;
            if(i > 0)
                cout << ", ";
        }
        else
        {
            count++;
            past_data = cur_data;
            cur_data = cur_data->next;
        }                
    }
    cout << ">" << "\n";
    return 0;
}
