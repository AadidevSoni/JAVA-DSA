//Brute Force
class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int count = 0;
        for(int i=0;i<n;i++) {
            int[] hash = new int[3];
            for(int j=i;j<n;j++) {
                hash[s.charAt(j)-'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) {
                    count++;
                }
            }
        }
        return count;
    }
}

//Better
class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int count = 0;
        for(int i=0;i<n;i++) {
            int[] hash = new int[3];
            for(int j=i;j<n;j++) {
                hash[s.charAt(j)-'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) {
                    count += n-j;
                    break; //we already added the no of substrings due to the rest of elements so we break out
                }
            }
        }
        return count;
    }
}

//Optimal
class Solution {
    public int numberOfSubstrings(String s) {
        int count = 0;
        int n = s.length();
        int[] lastSeen = {-1,-1,-1};
        for (int r = 0; r < n; r++) {
            int c = s.charAt(r);
            lastSeen[c-'a'] = r;
            
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int min = Integer.MAX_VALUE;
                int minIndex = Math.min(lastSeen[0],Math.min(lastSeen[1], lastSeen[2]));
                count += minIndex+1;
            }
        }
        return count;
    }
}