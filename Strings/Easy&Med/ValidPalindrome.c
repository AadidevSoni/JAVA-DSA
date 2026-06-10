class Solution {
    public boolean isPalindrome(String s) {
        String st = "";
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c >= 'a' && s.charAt(i) <= 'z') {
                st += c;
            }else if(c >= 'A' && c <= 'Z') {
                st += Character.toLowerCase(c);
            }else if(c >= '0' && c <= '9') {
                st += c;
            }
        }
        if(Palindrome(st)) {
            return true;
        }else {
            return false;
        }
    }

    public boolean Palindrome(String s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j) {
            if(s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}