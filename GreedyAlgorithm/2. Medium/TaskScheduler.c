class Solution {
    public int leastInterval(char[] tasks, int n) {
        int sz = tasks.length;
        int maxFreq = 0;
        int[] freq = new int[26];
        for(int i=0;i<sz;i++) {
            freq[tasks[i]-'A']++;
            if(freq[tasks[i]-'A'] > maxFreq)  {
                maxFreq = freq[tasks[i]-'A'];
            }
        }
        int countMax = 0;
        for(int i=0;i<26;i++) {
            if(freq[i] == maxFreq) {
                countMax++;
            }
        }
        return(Math.max(sz,(maxFreq-1) * (n+1) + countMax)); //n = 2 & A max with 3 A _ _ A _ _ A = (2 * 3) + 1
    }
}