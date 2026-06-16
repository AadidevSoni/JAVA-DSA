//TLE
class Solution {
    public int maxVowels(String s, int k) {
        int max = Integer.MIN_VALUE;
        int n = s.length();
        for(int i=0;i<=n-k;i++) {
            int num = 0;
            for(int j=i;j<i+k;j++) {
                if(isVowel(s.charAt(j))) {
                    num++;
                }
            }
            max = Math.max(max,num);
        }
        return max;
    }

    public boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
}

//Optimal
class Solution {
    public int maxVowels(String s, int k) {
        int count = 0;
        int n = s.length();
        for(int i=0;i<k;i++) {
            if(isVowel(s.charAt(i))) {
                count++;
            }
        }
        int max = count;
        for(int i=k;i<n;i++) {
            if(isVowel(s.charAt(i))) {
                count++;
            }
            if(isVowel(s.charAt(i-k))) {
                count--;
            }
            max = Math.max(max,count);
        }
        return max;
    }

    public boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
}