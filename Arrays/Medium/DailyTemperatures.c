//Slow
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ans = new int[n];
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(temperatures[j] > temperatures[i]) {
                    ans[i] = j-i;
                    break;
                }
            }
        }
        return ans;
    }
}

//Monotonic Stack - Fast
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>(); // stores indices
        
        for (int i = 0; i < n; i++) {
            // while current temperature is higher than temp at stack top
            while (!st.isEmpty() && temperatures[i] > temperatures[st.peek()]) {
                int idx = st.pop();
                ans[idx] = i - idx; // difference in days
            }
            st.push(i);
        }
        
        return ans;
    }
}
