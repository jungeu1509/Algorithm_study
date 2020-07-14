#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _Member {
    int number;
    int age;
    string name;
} member;

bool mem_check(_Member a, _Member b) {
    if(a.age == b.age)
        return a.number < b.number;
    else
        return a.age < b.age;
}

int main() {
    int N;
    member p[100000];
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> p[i].age >> p[i].name;
        p[i].number = i;
    }
    sort(p, p+N, mem_check);
    for(int i=0; i<N; i++)
        cout << p[i].age << " " << p[i].name <<"\n";
    return 0;
}
