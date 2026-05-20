class Solution {
    public boolean divisorGame(int n) {
        boolean res = f(0,n);
        return res;
    }

    public boolean f(int turn, int n) {
        if(n == 1) {
            if(turn == 0) {
                return false;
            }else {
                return true;
            }
        }
        for(int i=1;i<n;i++) {
            if(n%i == 0) {
                if(turn == 1) {
                    return f(0,n-i);
                }else {
                    return f(1,n-i);
                }
            }
        }
        if(turn == 0) {
                return false;
        }else {
            return true;
        }
    }
}