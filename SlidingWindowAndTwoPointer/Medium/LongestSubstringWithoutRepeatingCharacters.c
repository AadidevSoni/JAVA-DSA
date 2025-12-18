//Brute force 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxi = 0;
        for(int i=0;i<n;i++) {
            HashSet<Character> set = new HashSet<>();
            for(int j=i;j<n;j++) {
                char c = s.charAt(j);
                if(set.contains(c)) {
                    break;
                }
                int length = j-i+1;
                maxi = Math.max(maxi, length);
                set.add(c);
            }
        }
        return maxi;
    }
}

//Opimal 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while(r<n) {
            if(map.containsKey(s.charAt(r))) {
                if(map.get(s.charAt(r)) >= l) {
                    l = map.get(s.charAt(r))+1;
                }
            }
            int length = r-l+1;
            maxLen = Math.max(maxLen, length);
            map.put(s.charAt(r),r);
            r++;
        }
        return maxLen;
    }
}