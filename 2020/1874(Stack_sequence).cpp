#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<int> s;
    vector<char> check;
    vector<int> answer;
    int n, now = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        answer.push_back(input);        
    }
    
    for(int i = 0; i < n; i++)
    {
        while(now <= answer[i])
        {
            s.push(now);
            check.push_back('+');
            now++;
        }
        
        if(s.top() == answer[i])
        {
            check.push_back('-');
            s.pop();
        }
        else
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    for(int i = 0; i < check.size(); i++)
        cout << check[i] << '\n';
    return 0;
}
