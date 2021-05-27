#include <queue>
#include <iostream>
using namespace std;

int main() {
  priority_queue <int, vector<int>, greater<int> > pq;
  
  pq.push(5);
  pq.push(3);
  pq.push(6);
  pq.push(7);

  while(!pq.empty()) {
    int temp = pq.top();
    cout << temp;
    pq.pop();
  }
  
  return 0;
}
