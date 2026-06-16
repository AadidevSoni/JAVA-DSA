class Solution {
    public String processStr(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c >= 'a' && c <= 'z') {
                sb.append(c);
            }
            if(c == '*') {
                if(sb.length() != 0) {
                    sb.deleteCharAt(sb.length()-1);
                }
            }
            if(c == '#') {
                String curr = sb.toString();
                sb.append(curr);
            }
            if(c == '%') {
                sb = sb.reverse();
            }
        }
        return sb.toString();
    }
}