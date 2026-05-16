class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int n = moves.length();
        int left = 0;
        int right = 0;
        int blank = 0;
        for(int i=0;i<n;i++) {
            if(moves.charAt(i) == 'L') {
                left++;
            }
            if(moves.charAt(i) == 'R') {
                right++;
            }
            if(moves.charAt(i) == '_') {
                blank++;
            }
        }
        if(left >= right) {
            return(left + blank - right);
        }else {
            return(right + blank - left);
        }
    }
}