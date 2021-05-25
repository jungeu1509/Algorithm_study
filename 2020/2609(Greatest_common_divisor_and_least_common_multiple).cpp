#include <iostream>
using namespace std;
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int lcm(int a, int b){return a*b/gcd(a,b);}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << gcd(A, B) << '\n' << lcm(A, B) << '\n';
    return 0;
}
