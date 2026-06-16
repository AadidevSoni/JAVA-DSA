class Solution {
    public String removeStars(String s) {
        StringBuilder st = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s.charAt(i) == '*') {
                st.deleteCharAt(st.length()-1);
            }else {
                st.append(s.charAt(i));
            }
        }
        return st.toString();
    }
}