#include <iostream>
using namespace std;

int score[301];
int stair[301];

int main()
{
	int N, total=0;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> stair[i];
		total += stair[i];
	}

	if(N <= 2){
		cout << total << '\n';
		return 0;
	}

	for(int i = 1; i <= 3; i++){
		score[i] = stair[i];
	}
	for(int i = 4; i < N; i++){
		score[i] = ((score[i-2] < score[i-3])? score[i-2] : score[i-3]) + stair[i];
	}

	cout << total - ((score[N-1] < score[N-2])? score[N-1] : score[N-2]) << '\n';
    return 0;
}
