#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    stack<int> S;
    int len, answer;
    
    cin >> input;
    len = input.size();
    
    for(int i = 0 ; i < len ; i++) {
        if(input[i] == '(') {
            S.push(-2);
        }
        else if(input[i] == '[') {
            S.push(-3);
        }
        else if(input[i] == ']' || input[i] == ')') {
            if(S.empty()) {
                cout << 0;
                return 0;
            }
            
            if(input[i] == ')'){
                if(S.top() == -2 ) {
                    S.pop();
                    S.push(2);
                }
                else if(S.top() == -3){
                    cout<< 0;
                    return 0;
                }
                else {
                    answer =0;
                    while (S.top() != -2) {
                        answer += S.top();
                        S.pop();
                        if(S.empty()) {
                            cout << 0;
                            return 0;
                        }
                        else if(S.top() == -3 ){
                            cout << 0;
                            return 0;
                        }
                    }
                    S.pop();
                    S.push(answer * 2);
                }
            }
            else if(input[i]== ']') {
                if(S.top() == -3 ) {
                    S.pop();
                    S.push(3);
                }
                else if(S.top() == -2){
                    cout<< 0;
                    return 0;
                }
                else {
                    answer = 0;
                    while (S.top() != -3) {
                        answer += S.top();
                        S.pop();
                        if(S.empty()) {
                            cout << 0;
                            return 0;
                        }
                        else if(S.top() == -2 ){
                            cout << 0;
                            return 0;
                        }
                    }
                    S.pop();
                    S.push(answer * 3);
                }
            }
        }
        else {
            cout << 0;
            return 0;
        }
    }
    
    answer = 0;
    while (!S.empty()) {
        if(S.top() <= 0) {
            cout << 0;
            return 0;
        }
        answer += S.top();
        S.pop();
    }

    cout << answer << '\n';
    return 0;
}
