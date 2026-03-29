class Solution {
    public boolean canBeEqual(String s1, String s2) {
        for(int i=0;i<=1;i++) {
            int j = i+2;
            if((s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i)) || (s1.charAt(i) == s2.charAt(i) && s1.charAt(j) == s2.charAt(j))) {
                continue;
            }else {
                return false;
            }
        } 
        return true;
    }
}