import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;

public class Main {
    public static class Pair {
        int open, close;

        public Pair(int open, int close) {
            this.open = open;
            this.close = close;
        }
    }

    static private char[] input;
    static private ArrayList<Pair> pairArray = new ArrayList<>(); // check set of pair
    static private Stack<Pair> pairStack = new Stack<>(); // for dfs
    static private ArrayList<String> answerArray = new ArrayList<>();

    public static void main(String[] args) {
        try {
            // 입력
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String s = br.readLine();
            input = s.toCharArray();
            Stack<Integer> tempStack = new Stack<>();
            for(int i = 0; i < input.length; i++) {
                if(input[i] == '(') tempStack.push(i);
                else if(input[i] == ')') {
                    // 제일 안쪽 괄호부터 추가
                    pairArray.add(new Pair(tempStack.pop(), i));
                }
            }

            dfs(pairArray.size());
            Collections.sort(answerArray);
            String temp = "";
            for (String value : answerArray) {
                if(temp.equals(value)) continue;
                temp = value;
                System.out.println(value);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void dfs(int index) {
        // dfs에서 괄호를 제일 안쪽까지 확인했다면
        if(index <= 0) {
            StringBuilder answer = new StringBuilder();

            // 원본 문자열과 같다면 스킵
            if(pairStack.size() == 0) {
                return;
            }

            // 제거할 문자 체크
            ArrayList<Pair> tempArray = new ArrayList<>();
            boolean[] removeArray = new boolean[input.length];
            int i = 0;
            while(!pairStack.empty()) {
                Pair pop = pairStack.pop();
                tempArray.add(pop);
                removeArray[pop.open] = true;
                removeArray[pop.close] = true;
                i++;
            }
            for(int j = i-1; j >= 0; j--) {
                pairStack.push(tempArray.get(j));
            }
            for(int j = 0; j < input.length; j++){
                if(removeArray[j]) {
                    continue;
                }
                answer.append(input[j]);
            }
            answerArray.add(answer.toString());
            return;
        }

        // 제거 안하고 dfs 다음단계
        dfs(index-1);

        // 제거 하고 dfs 다음단계
        pairStack.push(pairArray.get(index-1));
        dfs(index-1);
        pairStack.pop();
    }
}
