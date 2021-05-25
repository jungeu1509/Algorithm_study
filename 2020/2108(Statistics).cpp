#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N, num[500000] ={0, };
    int sum = 0, count = 0, max_count = 0, answer = 0;
    queue< pair<int, int> > calculate;
    cin >> N;
    
    for(int j = 0 ; j < N ; j++)
    {
        cin >> num[j];
        sum += num[j];
    }
    cout << (int)round(sum / (double)N) << '\n';
    
    sort(num, num+N);
    cout << num[N/2] << '\n';
    
    if(N > 1)
    {
        for(int i = 1 ; i < N ; i++)
        {
            count++;
            if(num[i] != num[i-1])
            {
                if(max_count < count)
                    max_count = count;
                calculate.push(make_pair(num[i-1], count));
                count = 0;
            }
            else if(i == N-1)
            {
                count++;
                if(max_count < count)
                    max_count = count;
                calculate.push(make_pair(num[i], count));
            }
        }
        
        count = 0;
        while(!calculate.empty())
        {
            if(calculate.front().second == max_count)
            {
                count++;
                answer = calculate.front().first;
                if(count == 2)
                    break;
            }
            calculate.pop();
        }
    }
    else
        answer = num[0];
    cout << answer << '\n';
    
    cout << num[N-1] - num[0] << '\n';
    return 0;
}
