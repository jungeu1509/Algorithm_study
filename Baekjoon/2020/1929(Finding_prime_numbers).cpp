#include <iostream>
#include <vector>
using namespace std;

//Eratosthenes of Cyrene
int main()
{
    int M, N;
    vector<bool> v; // false = not primenumber / true = primenumber
    
    cin >> M >> N;
    
    for(int i = 0; i <= N ; i++) //push_back to check numbers
        v.push_back(true);
    
    v[1] = false; // 1 is not primenumber
        
    for(int i = 2; i * i <= N ; i++) // start 2
    {
        if(v[i])
            for(int j = i * i; j <= N ; j += i )
                v[j] = false;
    }

    for(int i = M ; i <= N ; i++)
        if(v[i])
            cout << i << '\n';
        
    return 0;
}
