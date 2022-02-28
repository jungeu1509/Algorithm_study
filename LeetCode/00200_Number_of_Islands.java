import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    class Map {
        int x;
        int y;
        public Map(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    public int numIslands(char[][] grid) {
        int answer = 0;
        Queue<Map> queue = new ArrayDeque<>();

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == '1') {
                    answer++;
                    queue.add(new Map(i, j));
                    grid[i][j] = '0';
                    
                    while (!queue.isEmpty()) {
                        Map now = queue.poll();
                        
                        for(int position = 0; position < dx.length; position++) {
                            Map next = new Map(now.x + dx[position], now.y + dy[position]);
                            if(next.x < 0 || next.x >= grid.length || next.y < 0 || next.y >= grid[0].length) continue;
                            if(grid[next.x][next.y] == '1') {
                                grid[next.x][next.y] = '0';
                                queue.add(new Map(next.x, next.y));
                            }
                        }
                    }
                    
                }
            }
        }

        return answer;
    }
}
