class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] nse = new int[n];
        int[] pse = new int[n];
        nse = findnse(heights);
        pse = findpse(heights);
        int max = 0;
        for(int i=0;i<n;i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            max = Math.max(max, area);
        }
        return max;
    }

    int[] findnse(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] nse = new int[n];
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]) { 
                st.pop();
            }

            if(st.isEmpty()) {
                nse[i] = n;
            }else {
                nse[i] = st.peek();
            }

            st.push(i); 
        }

        return nse;
    }

    int[] findpse(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] psee = new int[n];
        for(int i=0;i<n;i++) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]){
                st.pop();
            }

            if(st.isEmpty()) {
                psee[i] = -1;
            }else {
                psee[i] = st.peek();
            }

            st.push(i);
        }
        return psee;
    }
}