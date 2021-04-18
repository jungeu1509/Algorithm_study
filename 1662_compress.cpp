#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string input;
    stack< int > S;
    int output = 0, temp, count = 0;

    cin >> input;
    int size = input.size();

    for(int i = 0; i < size; i++) {
        if(input[i] == '(') {
            S.push(count - 1);
            count = 0;
            S.push(input[i-1] - '0');
            S.push(-1);
        }
        else if(input[i] == ')') {
            temp = count;
            count = 0;
            while(1) {
                if(S.top() != -1) {
                    temp += S.top();
                    S.pop();
                }
                else {
                    S.pop(); // S.top() == -1
                    temp *= S.top();
                    S.pop();
                    S.push(temp);
                    temp = 0;
                    break;
                }
            }
        }
        else{
            count++;
        }
    }

    S.push(count);

    while(!S.empty()) {
        output += S.top();
        S.pop();
    }

    cout << output << '\n';
    return 0;
}
