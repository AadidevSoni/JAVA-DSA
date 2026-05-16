class Solution {
    public List<String> commonChars(String[] words) {
        int[] minFreq = new int[26];
        Arrays.fill(minFreq, Integer.MAX_VALUE);
        for(String s: words) {
            int[] freq = new int[26];
            for(int i=0;i<s.length();i++) {
                freq[s.charAt(i)-'a']++;
            }
            for(int i=0;i<26;i++) {
                minFreq[i] = Math.min(minFreq[i], freq[i]);
            }
        }
        List<String> res = new ArrayList<>();
        for(int i=0;i<26;i++) {
            while(minFreq[i] > 0) {
                res.add(String.valueOf((char)(i+'a')));
                minFreq[i]--;
            }
        }
        return res;
    }
}