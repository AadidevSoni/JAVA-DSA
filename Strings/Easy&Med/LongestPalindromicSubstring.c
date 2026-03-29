class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean pali = false;
        int maxLen = Integer.MIN_VALUE;
        String maxPali = "";
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(isPalindrome(s.substring(i,j+1)) && j-i+1 > maxLen) {
                    maxLen = j-i+1;
                    maxPali = s.substring(i,j+1);
                }
            }
        }
        return maxPali;
    }

    public boolean isPalindrome(String s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i <= j) {
            if(s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}