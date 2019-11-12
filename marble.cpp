#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
	int ry, rx, by, bx, count;
}; // INFO ����ü ���� 

INFO start; // srart ��� ����ü ���Ŷ�� ���� 
char map[10][11]; // ���� ���� 


// bfs �Լ� 
int bfs() {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	int visited[10][10][10][10] = { 0, }; //
	queue<INFO> q; //queue ����ü  q  ���� 
	q.push(start); // q.����(start ��) 
	visited[start.ry][start.rx][start.by][start.bx] = 1; // �湮�߾����� ���� �Ǵ����� ���� 
	
	int ret = -1; //������� 
	while (!q.empty()) {//q�� ������� ������ ��� ���� 
		INFO cur = q.front();	//q �Ǿտ� �ִ� info����ü ������ 
		q.pop(); // q���� �� �տ� �ִ� �� ����� 
		if (cur.count > 10)	break; //10�� �̳��� �����ϴ��� ���� �Ǵ� 
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') //�ٳ����� ���� ���� ����� �ֱ� 
		{
			ret = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; ++dir) //���⿡ ���� ������ 
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
