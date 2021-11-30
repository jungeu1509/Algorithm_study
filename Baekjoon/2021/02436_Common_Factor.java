import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        long ans1 = 0L, ans2 = 0L;
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            long gcd = Long.parseLong(st.nextToken());
            long lcm = Long.parseLong(st.nextToken());

            if(gcd == lcm) {
                System.out.println(gcd + " " + gcd);
                return;
            }

            long xy = (int) (lcm / gcd);
            long x = 1;
            long y = xy;

            // xy의 약수 중 가운데 2개 구하기
            for(long i = xy / 2; i > 0 ; i-- ) {
                // 나누어 떨어지면 약수
                if(xy % i == 0) {
                    if(i <= x) {
                        // x, y 숫자 크기가 역전되면 반복문종료
                        break;
                    } else {
                        boolean flag = true;
                        // 서로소일 경우 임시 저장
                        for(long j = 2; j < x; j++) {
                            if((i % j == 0) && ((xy / i) % j == 0)) {
//                              // 서로소가 아님
                                flag = false;
                                break;
                            }
                        }
                        if(flag) {
                            y = i;
                            x = xy / i;
                        }
                    }
                }
            }

            // 약수 가운데 2개 중 작은것이 ans1, 큰것이 ans2
            ans1 = x * gcd;
            ans2 = y * gcd;

        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println(ans1 + " " + ans2);
    }
}
