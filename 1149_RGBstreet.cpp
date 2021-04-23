#include <iostream>
using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int map[1001][3];
int score[1001][3];

int main()
{
	int N, ret;
	cin >> N;

	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	for(int j = 0; j < 3; j++){
		score[1][j] = map[1][j];
	}

	for(int i = 2; i <= N; i++) {
		score[i][RED] = ((score[i-1][GREEN] < score[i-1][BLUE]) ? score[i-1][GREEN] : score[i-1][BLUE]) + map[i][RED];
		score[i][GREEN] = ((score[i-1][RED] < score[i-1][BLUE]) ? score[i-1][RED] : score[i-1][BLUE]) + map[i][GREEN];
		score[i][BLUE] = ((score[i-1][GREEN] < score[i-1][RED]) ? score[i-1][GREEN] : score[i-1][RED]) + map[i][BLUE];
	}

	ret = score[N][0];
	for(int i = 1; i < 3; i++){
		if(ret > score[N][i]) ret = score[N][i];
	}

	cout << ret << '\n';
    return 0;
}
