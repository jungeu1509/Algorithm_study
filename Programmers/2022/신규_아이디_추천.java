public class Solution {
    public String solution(String new_id) {
        
        String answer = "";
        
        // 1 step
        String step1 = "";
        step1 = new_id.toLowerCase();
        
        // 2 step
        String step2 = "";
        for(int i = 0 ; i < step1.length(); i++) {
            char now = step1.charAt(i);
            if(
                    (now >= 'a' && now <= 'z')
                    || (now >= '0' && now <= '9')
                    || (now == '-' || now == '_' || now == '.')
            ) {
                step2 += now;
            }
        }

        // 3 step
        String step3 = "";
        for(int i = 0; i < step2.length(); i++) {
            if(step2.charAt(i) == '.') {
                step3 += step2.charAt(i);
                boolean flag = true;
                while(flag) {
                    if(i == step2.length() - 1 ) break;
                    if(step2.charAt(++i) != '.'){
                        flag = false;
                        i--;
                    }
                }
            } else {
                step3 += step2.charAt(i);
            }
        }

        // 4 step
        String step4 = "";
        if(step3.charAt(0) != '.') step4 += step3.charAt(0);
        for(int i = 1; i < step3.length()-1; i++) {
            step4 += step3.charAt(i);
        }
        if(step3.charAt(step3.length()-1) != '.') step4 += step3.charAt(step3.length()-1);

        // 5 step
        String step5 = "";
        if(step4.equals("")) step5 = "a";
        else step5 = step4;

        // 6 step
        String step6 = "";
        int length = 15;
        if(step5.length() < length) length = step5.length();
        for(int i = 0; i < length; i++) {
            if(i == length - 1 && step5.charAt(i) == '.') break;
            step6 += step5.charAt(i);
        }

        // 7 step
        if(step6.length() == 1) answer = step6 + step6 + step6;
        else if(step6.length() == 2) answer = step6 + step6.charAt(1);
        else answer = step6;

        return answer;
    }

}
