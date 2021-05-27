#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef struct position_ {
    int X;
    int Y;
    int Z;
}position;

int main() {    
    int M, N, H, ans=0;
    int map[101][101][101] = {0, };
    int visit[101][101][101] = {0, };
    int dx[6] = {0, 0, -1, 1, 0, 0};
    int dy[6] = {1, -1, 0, 0, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    queue< position > Q;
    position P, cur, temp;
    
    cin >> M >> N >> H;
    for(int k = 1; k <= H; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1 ; j <= M ; j++) {
                cin >> map[k][i][j];
            }
        }
    }

    for(int k = 1; k <= H; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1 ; j <= M ; j++) {
                if(map[k][i][j] == 1) {
                    visit[k][i][j] = 0;
                    temp.Y=j;
                    temp.X=i;
                    temp.Z=k;
                    Q.push(temp);
                }
                else if(map[k][i][j] == 0){
                    visit[k][i][j] = -1;
                }
            }
        }
    }

    while(!Q.empty()){
        P = Q.front();
        Q.pop();
        for(int i = 0 ; i < 6 ; i++) {
            cur.X = P.X + dx[i];
            cur.Y = P.Y + dy[i];
            cur.Z = P.Z + dz[i];
            if(cur.X <= 0 || cur.X > N || cur.Y <= 0 || cur.Y > M || cur.Z <= 0 || cur.Z > H) continue;
            if(visit[cur.Z][cur.X][cur.Y] >= 0) continue;
            if(map[cur.Z][cur.X][cur.Y] == 0) {
                visit[cur.Z][cur.X][cur.Y] = visit[P.Z][P.X][P.Y] + 1;
                temp.X=cur.X;
                temp.Y=cur.Y;
                temp.Z=cur.Z;
                Q.push(temp);
            }
        }
    }

    for(int k = 1; k <= H; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1 ; j <= M ; j++) {
                if(visit[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
                if(ans < visit[k][i][j])
                    ans = visit[k][i][j];
            }
        }
    }
    cout << ans;
    return 0;
}
