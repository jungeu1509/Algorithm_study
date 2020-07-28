#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_CARD_SIZE 500000

int GET[MAX_CARD_SIZE];
int SET[MAX_CARD_SIZE];

int find_match_card(int size, int find_number);
int upper_bound_(int start, int end, int number);
int lower_bound_(int start, int end, int number);

int main()
{
    int N, M;
    
    cin >> N;
    for(int i=0; i< N; i++)
        cin >> GET[i];
    cin >> M;
    for(int i=0; i< M; i++)
        cin >> SET[i];
    sort(GET, GET+N);
    
    for(int i = 0; i < M; i++)
        cout << find_match_card(N, SET[i]) << " ";
    
    cout << '\n';
    return 0;
}

int find_match_card(int size, int find_number)
{
    int output = 0;
    int upper, lower;
    upper = upper_bound_(0, size, find_number);
    if(upper == -1)
        return output;
    
    lower = lower_bound_(0, upper, find_number);
    output = upper - lower + 1;
    
    return output;
}

int upper_bound_(int start, int end, int number)
{
    int ret = -1;
    int mean = (start + end) /2;
    if((end - start) <= 1)
    {
        if(GET[end] == number)
            return end;
        else if(GET[start] == number)
            return start;
        else
            return -1;
    }
    
    if(GET[mean] < number)
        ret = upper_bound_(mean+1, end, number);
    else if(GET[mean] > number)
        ret = upper_bound_(start, mean-1, number);
    else
        ret = upper_bound_(mean, end, number);
        
    return ret;
}

int lower_bound_(int start, int end, int number)
{
    int mean = (start + end) / 2;
    int ret;
    
    if((end - start) <= 1)
    {
        if(GET[start] == number)
            return start;
        else
            return end;
    }
    
    if(GET[mean] < number)
        ret = lower_bound_(mean+1, end, number);
    else
        ret = lower_bound_(start, mean, number);
        
    return ret;
}
