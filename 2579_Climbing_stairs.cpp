#include <iostream>
using namespace std;

#define DOUBLE	0
#define ONE	1

int score[301][3];
int stair[301];

void calc_score(int N) {
	int i = 3;
	while(i <= N){
		score[i][ONE] = score[i-1][DOUBLE] + stair[i];
		score[i][DOUBLE] = ((score[i-2][DOUBLE] > score[i-2][ONE]) ? score[i-2][DOUBLE] : score[i-2][ONE]) + stair[i];
		i++;
	}
	return;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> stair[i];
	}

	score[1][ONE] = stair[1];
	score[2][DOUBLE] = stair[2];
	score[2][ONE] = score[1][ONE] + stair[2];

	calc_score(N);
	cout << ((score[N][ONE] > score[N][DOUBLE]) ? score[N][ONE] : score[N][DOUBLE]) << '\n';
    return 0;
}
