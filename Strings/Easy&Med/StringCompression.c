class Solution {
    public int compress(char[] chars) {
        int i = 0;
        int indx = 0;
        int n = chars.length;
        while(i<n) {
            char c = chars[i];
            int j = i;
            while(j < n && chars[j] == c) {
                j++;
            }
            int len = j-i;
            chars[indx++] = c;
            if(len > 1) {
                String count = String.valueOf(len);
                for(char ch: count.toCharArray()) {
                    chars[indx++] = ch;
                }
            }
            i=j;
        }
        return indx;
    }
}