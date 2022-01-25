import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static boolean[][] connectList = new boolean[1000][1000];
    static boolean[] visit = new boolean[1000];
    static int N;
    static int M;

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            int answer = 0;

            for(int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int left = Integer.parseInt(st.nextToken()) - 1;
                int right = Integer.parseInt(st.nextToken()) - 1;
                connectList[left][right] = true;
                connectList[right][left] = true;
            }

            for(int i = 0; i < N; i++) {
                if(!visit[i]) {
                    visit[i] = true;
                    dfs(i);
                    answer++;
                }
            }
            System.out.println(answer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void dfs(int input) {
        for (int i = 0; i < N; i++) {
            if (connectList[input][i] && !visit[i]) {
                visit[i] = true;
                dfs(i);
            }
        }
    }
}
