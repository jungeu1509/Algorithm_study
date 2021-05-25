#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define X first
#define Y second

int main() {    
    int M, N, ans=0;
    int map[1001][1001] = {0, };
    int visit[1001][1001] = {0, };
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    queue< pair<int, int> > Q;
    pair<int, int> P, cur;
    
    cin >> M >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1 ; j <= M ; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1 ; j <= M ; j++) {
            if(map[i][j] == 1) {
                visit[i][j] = 0;
                Q.push({i, j});
            }
            else if(map[i][j] == 0){
                visit[i][j] = -1;
            }
        }
    }

    while(!Q.empty()){
        P = Q.front();
        Q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            cur.X = P.X + dx[i];
            cur.Y = P.Y + dy[i];
            if(cur.X <= 0 || cur.X > N || cur.Y <= 0 || cur.Y > M) continue;
            if(visit[cur.X][cur.Y] >= 0) continue;
            if(map[cur.X][cur.Y] == 0) {
                visit[cur.X][cur.Y] = visit[P.X][P.Y] + 1;
                Q.push({cur.X, cur.Y});
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j =1 ; j <= M ; j++) {
            if(visit[i][j] == -1) {
                cout << -1;
                return 0;
            }
            if(ans < visit[i][j])
                ans = visit[i][j];
        }
    }
    cout << ans;
    return 0;
}
