#include <iostream>
#include <string>
using namespace std;

#define MAX_DEQUE_SIZE 10000

typedef struct DEQUE
{
    int front;
    int rear;
    int size;
}Deque_State;

int deque[MAX_DEQUE_SIZE];
Deque_State deque_state;

void init_deque()
{
    deque_state.front = 0;
    deque_state.rear = 0;
    deque_state.size = 0;

    for(int i=0;i<MAX_DEQUE_SIZE;i++)
        deque[i] = 0;

    return;
}

void push_front(int x)
{
    deque[deque_state.front] = x;
    deque_state.front = (deque_state.front + 1) % MAX_DEQUE_SIZE;
    deque_state.size++;
    return;
}

void push_back(int x)
{
    deque_state.rear = (deque_state.rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    deque[deque_state.rear] = x;
    deque_state.size++;
    return ;
}

int pop_front()
{
    int temp;
    if(deque_state.size == 0)
        return -1;

    deque_state.front = (deque_state.front - 1 + MAX_DEQUE_SIZE ) % MAX_DEQUE_SIZE;

    temp = deque[deque_state.front];
    deque[deque_state.front] = 0;

    deque_state.size--;
    return temp;
}

int pop_back()
{
    if(deque_state.size == 0)
        return -1;

    int temp = deque[deque_state.rear];
    deque[deque_state.rear] = 0;

    deque_state.rear = (deque_state.rear + 1 ) % MAX_DEQUE_SIZE;

    deque_state.size--;
    return temp;
}

int size()
{return deque_state.size;}

bool empty()
{return (deque_state.size == 0);}

int front()
{
    if(empty())
        return -1;

    if(deque_state.front == 0)
        return deque[MAX_DEQUE_SIZE - 1];
    else
        return deque[deque_state.front - 1];
}

int back()
{
    if(empty())
        return -1;
    else
        return deque[deque_state.rear];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, n;
    string command;
    init_deque();
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> command;
        if(command == "push_front")
        {
            cin >> n;
            push_front(n);;
        }
        else if(command == "push_back")
        {
            cin >> n;
            push_back(n);
        }
        else if(command == "pop_front")
            cout << pop_front() << "\n";
        else if(command == "pop_back")
            cout << pop_back() << "\n";
        else if(command == "size")
            cout << size() << "\n";
        else if(command == "empty")
            cout << empty() << "\n";
        else if(command == "front")
            cout << front() << "\n";
        else if(command == "back")
            cout << back() << "\n";
    }
    return 0;
}
