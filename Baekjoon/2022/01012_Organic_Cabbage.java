import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
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

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            int T = Integer.parseInt(br.readLine());

            for(;T>0;T--) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int M = Integer.parseInt(st.nextToken());
                int N = Integer.parseInt(st.nextToken());
                int K = Integer.parseInt(st.nextToken());
                int[][] map = new int[N][M];
                int answer = 0;

                for(int i = 0; i < K; i++) {
                    st = new StringTokenizer(br.readLine());
                    int X = Integer.parseInt(st.nextToken());
                    int Y = Integer.parseInt(st.nextToken());
                    map[Y][X] = 1;
                }

                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < M; j++) {
                        Queue<Map> mapQueue = new ArrayDeque<>();
                        if(map[i][j] == 1) {
                            answer++;
                            mapQueue.add(new Map(j, i));
                            map[i][j] = -1;
                            while(!mapQueue.isEmpty()) {
                                Map now = mapQueue.poll();

                                for(int k = 0; k < dx.length; k++) {
                                    Map next = new Map(now.x+dx[k], now.y+dy[k]);
                                    if(next.x < 0 || next.x >= M || next.y < 0 || next.y >= N) continue;
                                    if(map[next.y][next.x] == 1) {
                                        mapQueue.add(next);
                                        map[next.y][next.x] = -1;
                                    }
                                }
                            }
                        }
                    }
                }

                System.out.println(answer);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
