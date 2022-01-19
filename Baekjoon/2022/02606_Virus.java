import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static class Network {
        int left;
        int right;

        public Network(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public static void main(String[] args) {
        try {
            // 입력
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            int computer = Integer.parseInt(br.readLine());
            int net = Integer.parseInt(br.readLine());

            List<Network> networkList = new ArrayList<>();
            Boolean[] computerList = new Boolean[computer];
            Arrays.fill(computerList, false);

            for(int i = 0 ; i < net ; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                networkList.add(new Network(a, b));
            }

            Stack<Integer> virus = new Stack<>();
            virus.push(1);

            while(!virus.isEmpty()) {
                Integer pop = virus.pop();
                if(!computerList[pop - 1]) {
                    computerList[pop - 1] = true;
                    for(int i = 0; i < net ; i++) {
                        Network network = networkList.get(i);
                        if(network.left == pop) {
                            virus.push(network.right);
                        } else if(network.right == pop) {
                            virus.push(network.left);
                        }
                    }
                }
            }

            int count = 0;
            for (Boolean aBoolean : computerList) {
                if (aBoolean) count++;
            }

            System.out.println(count - 1);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
