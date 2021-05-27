#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int n, m, num=0, max=0, count=0;
    int map[501][501] = {0, };
    int visit[501][501] = {0, };
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    pair<int, int> p, cur;
    queue< pair<int,int> > q;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == 1 && visit[i][j] == 0) {
                count = 0;
                num++;
                q.push({i, j});
                visit[i][j] = 1;
                
                while(!q.empty()){
                    p = q.front();
                    q.pop();
                    count ++;
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        cur.first = p.first + dy[k];
                        cur.second = p.second + dx[k];
                        
                        if(cur.first <= 0 || cur.first > n || cur.second <= 0 || cur.second > m)
                            continue;
                            
                        if(map[cur.first][cur.second] == 1 && 
                                    visit[cur.first][cur.second] == 0) {
                            q.push({cur.first, cur.second});
                            visit[cur.first][cur.second] = 1;
                        }
                    }
                }
                
                if(max < count)
                    max = count;

            }
        }
    }
    
    cout << num << '\n' << max;
    
    return 0;
}
