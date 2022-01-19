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
    
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] answer = new int[m][n];

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                Queue<Map> mapQueue = new ArrayDeque<>();
                mapQueue.add(new Map(i, j));
                int[][] visit = new int[m][n];
                while (!mapQueue.isEmpty()) {
                    Map now = mapQueue.poll();
                    // 0일경우 현재 거리 저장 후 다음 칸 확인
                    if(mat[now.x][now.y] == 0) {
                        answer[i][j] = visit[now.x][now.y];
                        break;
                    }

                    // 0이 아닐경우 주위 칸 저장
                    // 상하좌우 순서
                    for(int k = 0; k < 4; k++) {
                        int nextX = now.x+dx[k];
                        int nextY = now.y+dy[k];
                        if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visit[nextX][nextY] != 0) continue;
                        Map next = new Map(nextX, nextY);
                        visit[nextX][nextY] = visit[now.x][now.y] + 1;

                        mapQueue.add(next);
                    }
                }
            }
        }

        return answer;
    }
}
