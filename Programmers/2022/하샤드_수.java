class Solution {
    public boolean solution(int x) {
        int div = x;
        int sum = 0;
        
        while(div != 0) {
            sum += div % 10;
            div /= 10;
        }

        return (x % sum == 0);
    }
}
