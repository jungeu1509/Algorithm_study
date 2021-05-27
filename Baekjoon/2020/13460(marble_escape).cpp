#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
	int ry, rx, by, bx, count;
}; // INFO 구조체 정의 

INFO start; // srart 라는 구조체 쓸거라고 선언 
char map[10][11]; // 지도 선언 


// bfs 함수 
int bfs() {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	int visited[10][10][10][10] = { 0, }; //
	queue<INFO> q; //queue 구조체  q  선언 
	q.push(start); // q.넣자(start 값) 
	visited[start.ry][start.rx][start.by][start.bx] = 1; // 방문했었는지 여부 판단위해 선언 
	
	int ret = -1; //결과값값 
	while (!q.empty()) {//q가 비어있지 않으면 계속 실행 
		INFO cur = q.front();	//q 맨앞에 있는 info구조체 가져옴 
		q.pop(); // q에서 맨 앞에 있는 값 지우기 
		if (cur.count > 10)	break; //10번 이내에 수행하는지 여부 판단 
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') //다끝나면 현재 상태 결과값 주기 
		{
			ret = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; ++dir) //방향에 따라 움직임 
		{
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (1) {
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
					next_ry += dy[dir], next_rx += dx[dir];
				}
				else {
					if (map[next_ry][next_rx] == '#') {
						next_ry -= dy[dir], next_rx -= dx[dir];
					}
					break;
				}
			}

			while (1) {
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
					next_by += dy[dir], next_bx += dx[dir];
				}
				else {
					if (map[next_by][next_bx] == '#') {
						next_by -= dy[dir], next_bx -= dx[dir];
					}
					break;
				}
			}

			if (next_ry == next_by && next_rx == next_bx) {
				if (map[next_ry][next_rx] != 'O') {
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
					if (red_dist > blue_dist) {
						next_ry -= dy[dir], next_rx -= dx[dir];
					}
					else {
						next_by -= dy[dir], next_bx -= dx[dir];
					}
				}
			}

			if (visited[next_ry][next_rx][next_by][next_bx] == 0) {
				visited[next_ry][next_rx][next_by][next_bx] = 1;
				INFO next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		}
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (map[y][x] == 'R') {
				start.ry = y, start.rx = x;
			}
			if (map[y][x] == 'B') {
				start.by = y, start.bx = x;
			}
		}
	}
	start.count = 0;

	int ret = bfs();
	printf("%d\n", ret);

	return 0;
}
