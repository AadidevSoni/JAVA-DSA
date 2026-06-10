class Solution {
    public String mergeAlternately(String word1, String word2) {
        int i = 0;
        int j = 0;
        int n = word1.length();
        int m = word2.length();
        String s = "";
        while(i < n && j < m) {
            s += word1.charAt(i);
            s += word2.charAt(j);
            i++;
            j++;
        }
        if(i != n) {
            while(i < n) {
                s += word1.charAt(i);
                i++;
            }
        }
        if(j != m) {
            while(j < m) {
                s += word2.charAt(j);
                j++;
            }
        }
        return s;
    }
}