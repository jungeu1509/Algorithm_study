class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int div = x;
        int sum = 0;
        
        while(div != 0) {
            sum += div % 10;
            div /= 10;
        }
        
        if(x % sum == 0) answer = true;
        else answer = false;
        
        return answer;
    }
}
