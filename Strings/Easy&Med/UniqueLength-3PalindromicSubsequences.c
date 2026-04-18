//TLE 

class Solution {
    public int countPalindromicSubsequence(String s) {
        Set<String> set = new HashSet<>();
        gen(s, 0, "", set);
        return set.size();
    }

    public static void gen(String s, int index, String current, Set<String> set) {
        if(current.length() == 3) {
            if(isPalindrome(current)) {
                set.add(current);
            }
            return;
        }
        if(index == s.length()) {
            return;
        }
        gen(s,index+1,current+s.charAt(index),set);
        gen(s,index+1,current,set);
    }

    public static boolean isPalindrome(String s) {
        int i =0;
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

//Optimized

class Solution {
    public int countPalindromicSubsequence(String s) {
        int count = 0;
        int n = s.length();
        for(char ch='a';ch <= 'z';ch++) {
            int left = -1;
            int right = -1;
            for(int i=0;i<n;i++) {
                if(s.charAt(i) == ch) {
                    if(left == -1) {
                        left = i;
                    }else {
                        right = i;
                    }
                }
            }
            if(left == -1 || right == -1) continue;

            int[] found = new int[26];
            for(int k = left+1;k <=right-1;k++) {
                found[s.charAt(k)-'a']++;
            }

            for(int b: found) {
                if(b != 0) {
                    count++;
                }
            }
        }

        return count;
    }
}