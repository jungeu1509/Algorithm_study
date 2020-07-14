#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b)
{
    if(a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main() {
    int N, j=0;
    string word[20000];
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> word[j];
        for(int k = 0; k < j; k++)
        {
            if(word[j] == word[k])
            {
                j--;
                break;
            }
        }
        j++;
    }
    sort(word, word+j, compare);
    for(int i = 0; i < j; i++)
    {
        cout << word[i] <<"\n";
    }
    return 0;
}
