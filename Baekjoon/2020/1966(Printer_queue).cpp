#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int data;
    int importance;
}print_document;

int main()
{
    int T, N, M;
    cin >> T;
    
    for(int testcase = 0; testcase < T ; testcase++)
    {
        queue<print_document> q;
        priority_queue<int> pq;
        print_document now = {0, };
        int count = 0;
        cin >> N >> M;
        
        for(int j = 0 ; j < N ; j++)
        {
            int input;
            cin >> input;
            now.importance = input;
            now.data = j;
            q.push(now);
            pq.push(input);
        }
        
        while(!q.empty())
        {
            now.data = q.front().data;
            now.importance = q.front().importance;
            q.pop();
            
            if(pq.top() == now.importance)
            {
                pq.pop();
                count++;
                if(now.data == M)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else
                q.push(now);
        }
    }    
    return 0;
}
