#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string input;
    unsigned int size, stick=0, ret=0;
    bool flag = 0;
    cin >> input;
    stack<char> S;
    
    size = input.size();
    
    for(int i = 0 ; i < size ; i++) {
        if(input[i] == '(') {
            if(input[i+1] == '(') {
                S.push(input[i]);
                stick++;
            }
            else{
                ret += stick;
                i++;
            }
        }
        else {
            S.pop();
            stick--;
            ret++;
        }
    }
    cout << ret;
    return 0;
}
