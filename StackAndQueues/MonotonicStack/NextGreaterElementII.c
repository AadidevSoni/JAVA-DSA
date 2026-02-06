//Brute force
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];
        for(int i=0;i<n;i++) {
            int t = 0;
            for(int j=i+1;j<=i+n-1;j++) {
                int ind = j%n;
                if(nums[ind] > nums[i]) {
                    t++;
                    arr[i] = nums[ind];
                    break;
                }
            }
            if(t == 0) {
                arr[i] = -1;
            }
        }
        return arr;
    }
}

//Monotonic
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int n = nums.length;
        int[] res = new int[n];
        for(int i=(2*n)-1;i>=0;i--){
            int ind = i%n;
            while(!st.isEmpty() && st.peek() <= nums[ind]) {
                st.pop();
            }
            if(i < n) {
                if(st.isEmpty()) {
                    res[i] = -1;
                }else {
                    res[i] = st.peek();
                }
            }
            st.push(nums[ind]);
        }
        return res;
    }
}