#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int main() {
    int n, m;
    char map[101][101]= {0, };
    int visit[101][101]= {0, };
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    queue< pair<int, int> > q;
    pair<int, int> p, cur;
    
    cin >> n >> m;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= m ; j++) {
            cin >> map[i][j];
        }
    }
    
    q.push({1,1});
    visit[1][1] = 1;
    
    while(!q.empty()){
        p = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            cur.X = p.X + dx[k];
            cur.Y = p.Y + dy[k];
            
            if(cur.X <= 0 || cur.X > n || cur.Y <=0 || cur.Y > m)
                continue;
            
            if(map[cur.X][cur.Y] == '1' && visit[cur.X][cur.Y] == 0) {
                visit[cur.X][cur.Y] = visit[p.X][p.Y] + 1;
                q.push(cur);
            }
        }
    }
    
    cout << visit[n][m];
    return 0;
}
