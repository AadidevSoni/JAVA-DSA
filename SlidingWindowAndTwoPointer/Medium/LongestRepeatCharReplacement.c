//Brute Force
class Solution {
    public int characterReplacement(String s, int k) {
        int maxLen = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            int[] hash = new int[26];
            int maxf = 0;
            for(int j=i;j<n;j++) {
                hash[s.charAt(j)-'A']++;
                maxf = Math.max(maxf,hash[s.charAt(j)-'A']);
                int changes = (j-i+1) - maxf;
                if(changes <= k) {
                    maxLen = Math.max(maxLen,j-i+1);
                }else {
                    break;
                }
            }   
        }
        return maxLen;
    }
}

//Optimal
class Solution {
    public int characterReplacement(String s, int k) {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        int[] hash = new int[26];
        int maxF = 0;
        while(r < n) {
            hash[s.charAt(r)-'A']++;
            maxF = Math.max(maxF,hash[s.charAt(r)-'A']);
            int changes = (r-l+1) - maxF;
            if(changes <= k) {
                maxLen = Math.max(maxLen,(r-l+1));
            }else {
                while((r-l+1) - maxF > k) {
                    hash[s.charAt(l)-'A']--;
                    maxF = 0;
                    for(int i=0;i<26;i++) {
                        if(hash[i] > maxF) {
                            maxF = hash[i];
                        }
                    }
                    l++;
                }
            }
            r++;
        }
        return maxLen;
    }
}

//Best

class Solution {
    public int characterReplacement(String s, int k) {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        int[] hash = new int[26];
        int maxF = 0;
        while(r < n) {
            hash[s.charAt(r)-'A']++;
            maxF = Math.max(maxF,hash[s.charAt(r)-'A']);
            int changes = (r-l+1) - maxF;
            if(changes <= k) {
                maxLen = Math.max(maxLen,(r-l+1));
            }else {
                hash[s.charAt(l)-'A']--;
                maxF = 0;
                for(int i=0;i<26;i++) {
                    if(hash[i] > maxF) {
                        maxF = hash[i];
                    }
                }
                l++;
            }
            r++;
        }
        return maxLen;
    }
}