#include <iostream>
using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int map[1001][3];

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
		map[1][j] = map[1][j];
	}

	for(int i = 2; i <= N; i++) {
		map[i][RED] = ((map[i-1][GREEN] < map[i-1][BLUE]) ? map[i-1][GREEN] : map[i-1][BLUE]) + map[i][RED];
		map[i][GREEN] = ((map[i-1][RED] < map[i-1][BLUE]) ? map[i-1][RED] : map[i-1][BLUE]) + map[i][GREEN];
		map[i][BLUE] = ((map[i-1][GREEN] < map[i-1][RED]) ? map[i-1][GREEN] : map[i-1][RED]) + map[i][BLUE];
	}

	ret = map[N][0];
	for(int i = 1; i < 3; i++){
		if(ret > map[N][i]) ret = map[N][i];
	}

	cout << ret << '\n';
    return 0;
}
