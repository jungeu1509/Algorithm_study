import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        if(s.length()%2 != 0) return answer;

        for(int i = 0 ; i < s.length(); i++) {
            String input = s.substring(i);
            if(i > 0) input += s.substring(0, i);

            if(checker(input)) answer++;
        }
        return answer;
    }

    boolean checker(String s) {
        boolean answer = false;
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            char now = s.charAt(i);
            switch (now) {
                case '(':
                case '[':
                case '{':
                    stack.add(now);
                    break;
                case ')':
                    if(!stack.isEmpty() && stack.peek() == '(') stack.pop();
                    else return answer;
                    break;
                case ']':
                    if(!stack.isEmpty() && stack.peek() == '[') stack.pop();
                    else return answer;
                    break;
                case '}':
                    if(!stack.isEmpty() && stack.peek() == '{') stack.pop();
                    else return answer;
                    break;
            }
        }
        if(stack.isEmpty()) answer = true;
        return answer;
    }
}
