class Solution {
    public String solution(String s, int n) {
        String answer = "";

        for(int i = 0; i < s.length(); i++) {
            char now = s.charAt(i);

            int temp = ' ';
            if(now >= 'a' && now <= 'z') {
                temp = now + n;
                if(temp > 'z') temp -= 26;
            } else if (now >= 'A' && now <= 'Z') {
                temp = now + n;
                if(temp > 'Z') temp -= 26;
            }

            answer += (char)temp;
        }

        return answer;
    }
}
