import java.util.Arrays;

class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 60000000;
        int[][] map = new int[n+1][n+1];
        for (int[] ints : map) {
            Arrays.fill(ints, (20000000));
        }

        for (int[] fare : fares) {
            map[fare[0]][fare[1]] = fare[2];
            map[fare[1]][fare[0]] = fare[2];
        }

        for(int i = 1; i <= n; i++) {
            map[i][i] = 0;
        }

        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(map[i][j] > map[i][k] + map[k][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            int temp = map[s][i] + map[i][a] + map[i][b];
            if(temp < answer) {
                answer = temp;
            }
        }

        return answer;
    }
}
