class Solution {
    public int getLength(int[] nums) {
        int n = nums.length;
        int res = 1;
        for(int i=0;i<n;i++) {
            Map<Integer, Integer> freq = new HashMap<>();
            Map<Integer, Integer> freqNum = new HashMap<>();
            int maxFreq = 0;
            for(int j=i;j<n;j++) {
                int y = nums[j];
                int currFreq = freq.getOrDefault(y,0);
                if(currFreq > 0) {
                    freqNum.put(currFreq, freqNum.get(currFreq)-1);
                    if(freqNum.get(currFreq) == 0) {
                        freqNum.remove(currFreq);
                    }
                }
                int frequency = currFreq + 1;
                freq.put(y,frequency);
                freqNum.put(frequency,freqNum.getOrDefault(frequency,0)+1);
                maxFreq = Math.max(maxFreq,frequency);
                if(isBalanced(maxFreq,freqNum,freq.size())) {
                    res = Math.max(res,j-i+1);
                }
            }
        }
        return res;
    }

    public boolean isBalanced(int maxFreq, Map<Integer,Integer> freqNum, int num) {
        if(freqNum.size() == 1) {
            return num == 1;
        }
        if(freqNum.size() != 2) {
            return false;
        }
        if(maxFreq % 2 != 0) {
            return false;
        }
        int half = maxFreq/2;
        return(freqNum.containsKey(maxFreq) && freqNum.containsKey(half));
    }
}©leetcode