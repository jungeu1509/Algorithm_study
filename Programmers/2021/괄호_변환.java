class Solution {
    public String solution(String p) {
        String answer = "";
        answer = makeRightString(p);
        return answer;
    }

    private String makeRightString(String string) {
        String answer = "";
        char[] input = string.toCharArray();
        if(input.length == 0) {return answer;}
        Integer front = 0, back = 0 ,i;
        for(i = 0; i < input.length ; i++) {
            if(input[i] == '(') {
                front++;
            } else {
                back++;
            }
            if(front.equals(back)) {
                break;
            }
        }
        String frontString = string.substring(0, i+1);
        System.out.println("frontString : "+frontString);
        String backString = "";
        if(i + 2 <= input.length - 1) {
            backString = string.substring(i + 1);
        }
        if(checkString(frontString)) {
            answer += frontString;
            answer += makeRightString(backString);
        } else {
            answer += '(';
            answer += makeRightString(backString);
            answer += ')';
            char[] temp = frontString.toCharArray();
            for(int j = 1; j < temp.length-1; j++) {
                if(temp[j] == '(') answer += ')';
                else answer += '(';
            }
        }
        
        return answer;
    }

    private boolean checkString(String string) {
        char[] input = string.toCharArray();
        return input[0] == '(';
    }
}
