class Solution {
    public boolean hasAlternatingBits(int n) {
        String bin = Integer.toBinaryString(n);
        int l = bin.length();
        for(int i=0;i<l;i++) {
            if(i == 0) {
                continue;
            }
            if(bin.charAt(i-1) == bin.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}