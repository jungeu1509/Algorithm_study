#include <iostream>
#include <queue>

using namespace std;

typedef struct position_{
    char name;
    int X;
    int Y;
}position;

int main() {
    char map[1002][1002];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int R, C;
    int j_cnt = 0;
    queue< position > Q;
    position point, cur;
    
    int** visit = new int*[1002];
    for(int i = 0; i < 1002; ++i)
    visit[i] = new int[1002];
    int** F_visit = new int*[1002];
    for(int i = 0; i < 1002; ++i)
    F_visit[i] = new int[1002];
    
    /* 입력 */
    cin >> R >> C;
    for(int i = 1; i <= R ; i++) {
        for(int j = 1 ; j <= C ; j++) {
            cin >> map[i][j];
        }
    }
    
    /* 지도에 따른 불과 지훈의 이동 위치 초기값 입력 */
    for(int i = 1; i <= R ; i++) {
        for(int j = 1 ; j <= C ; j++) {
            if(map[i][j] == '#') { /* 벽일경우 이동 불가 */
                visit[i][j] = -1;
                F_visit[i][j] = -1;
            }
            else if(map[i][j] == 'F') { /* 불 위치일 경우 지훈 이동 불가 및 불 위치 지정 */
                F_visit[i][j] = 1;
                visit[i][j] = -1;
                point.name = 'F';
                point.Y = i;
                point.X = j;
                Q.push(point); /* 불이 여러개일 가능성 */
            }
            else if(map[i][j] == 'J') { /* 지훈 위치일 경우 지훈 위치 지정 */
                visit[i][j] = 1;
                cur.name = 'J';
                cur.Y = i;
                cur.X = j;
            }
        }
    }
    Q.push(cur); /* 지훈은 무조건 한명 */
    j_cnt++;/* 경우의 수 확인용 카운트 */
    
    if(cur.X == 1 || cur.X == C || cur.Y == 1 || cur.Y == R) {
        cout << 1;
        return 0;
    }
    
    while(!Q.empty() && j_cnt!=0) { /* Q 로 이동 경우의 수 종료 확인 && 지훈 이동 경우의 수 확인 - 지훈 이동 종료되면 반복문 탈출*/
        point = Q.front();
        Q.pop();
        
        if(point.name == 'F') {
            for(int i = 0 ; i < 4 ; i++) {
                cur.X = point.X + dx[i]; /* 불의 다음 이동 상하좌우 확인 */
                cur.Y = point.Y + dy[i];
                if(cur.X <= 0 || cur.X > C || cur.Y <= 0 || cur.Y > R ) continue; /* 지도 밖일 경우 스킵 */
                if(map[cur.Y][cur.X] == '#') continue; /* 벽일 경우 스킵 */
                if(F_visit[cur.Y][cur.X] > 0 ) continue; /* 이미 지나온 길일경우 스킵 */
                
                F_visit[cur.Y][cur.X] = F_visit[point.Y][point.X] + 1; /* 불이 번지는 1초 추가 */
                cur.name = 'F';
                Q.push(cur); /* 큐에 추가 */
                
            }
        }
        else {
            j_cnt--; /* 지훈일 경우의 수 추출 - 큐에 지훈의 경우의 수 확인 */
            for(int i = 0 ; i < 4 ; i++) {
                cur.X = point.X + dx[i]; /* 지훈의 다음 이동 상하좌우 확인 */
                cur.Y = point.Y + dy[i];
                if(cur.X <= 0 || cur.X > C || cur.Y <= 0 || cur.Y > R) continue; /* 지도 밖일경우 스킵 */
                if(visit[cur.Y][cur.X] == -1) continue; /* 벽이거나 불 시작 위치일경우 스킵 */
                if(visit[cur.Y][cur.X] > 0 ) continue; /* 이미 지나온길일경우 스킵 */
                if(F_visit[cur.Y][cur.X] > 0 && (F_visit[cur.Y][cur.X] <= (visit[point.Y][point.X] + 1))) continue; /* 불이 먼저 혹은 동시에 도착할경우 스킵 */
                
                if(cur.X == 1 || cur.X == C || cur.Y == 1 || cur.Y == R) { /* 벽에 달라붙을경우 상황 종료 */
                    cout << (visit[point.Y][point.X] +1); /* 처음 시작을 1로 시작했고 움직인 칸만큼 1씩 더해짐 마지막에 벽에 붙은 후 한칸 더 가야하므로 +1만 하면 된다.*/
                    return 0;
                }
                
                visit[cur.Y][cur.X] = visit[point.Y][point.X] + 1; /* 1초 추가 */
                cur.name = 'J';
                Q.push(cur);
                j_cnt++;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
