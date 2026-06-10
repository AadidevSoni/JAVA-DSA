//Brute Force
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        List<Integer> lst = new ArrayList<>();
        for(int i=0;i<=n-k;i++) {
            int max = nums[i];
            for(int j=i;j<=i+k-1;j++) {
                max = Math.max(max,nums[j]);
            }
            lst.add(max);
        }
        int sz = lst.size();
        int[] res = new int[sz];
        for(int i=0;i<sz;i++) {
            res[i] = lst.get(i);
        }
        return res;
    }
}

//Optimal 
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>(); //dq can push and pop from front and back
        int n = nums.length;
        int[] res = new int[n-k+1];
        int ind = 0;
        for(int i=0;i<n;i++) {
            if(!dq.isEmpty() && dq.peekFirst() <= i-k) { //element went behind the window
                dq.pollFirst(); 
            }
            while(!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }
            dq.offerLast(i);
            if(i >= k-1) {
                res[ind] = nums[dq.peekFirst()];
                ind++;
            }
        }
        return res;
    }
}