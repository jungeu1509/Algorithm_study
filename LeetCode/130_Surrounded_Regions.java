import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public static class Map{
        int x;
        int y;

        public Map(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    
    public void solve(char[][] board) {
        Queue<Map> queue = new ArrayDeque<>();
        int m = board.length;
        int n = board[0].length;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char answer = 'X'; // Error
                if(board[i][j] == 'O') {
                    board[i][j] = 'T'; // Temp
                    queue.add(new Map(j, i));
                    //bfs();
                    while(!queue.isEmpty()) {
                        Map now = queue.poll();
                        for(int k = 0; k < 4; k++) {
                            Map next = new Map(now.x + dx[k], now.y + dy[k]);
                            // 벽이 부딛히면 무조건 O 상태
                            if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) {
                                answer = 'P'; // Pass
                                continue;
                            }
                            // 주변이 O인지 확인
                            if(board[next.y][next.x] == 'O') {
                                board[next.y][next.x] = 'T';
                                queue.add(new Map(next.x, next.y));
                            }
                        }
                    }
                }

                for(int ii = 0; ii < m; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if(board[ii][jj] == 'T') board[ii][jj] = answer;
                    }
                }
            }
        }

        for(int ii = 0; ii < m; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if(board[ii][jj] == 'P') board[ii][jj] = 'O';
            }
        }
    }
}
