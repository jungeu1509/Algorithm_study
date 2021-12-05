import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        int ans = 0;
        String[] S;
        try {
            // 입력
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            S = new String[N];

            for(int i = 0; i < N; i++) {
                S[i] = br.readLine();
            }
            
            for(int i = 0; i < M; i++) {
                String str = br.readLine();
                for(int j = 0; j < N; j++) {
                    if(S[j].equals(str)) ans++;
                }
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(ans);
    }
}
