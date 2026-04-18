class Solution {
    public int lengthOfLastWord(String s) {
        int length = 0;
        int n = s.length();
        for(int i=n-1;i>=0;i--) {
            if(s.charAt(i) != ' ') {
                length++;
            }else {
                if(length == 0) {
                    continue;
                }else {
                    return length;
                }
            }
        }
        return length;
    }
}