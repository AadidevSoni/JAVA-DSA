class Solution {
    public long subArrayRanges(int[] nums) {
        long sumLargest = 0;
        long sumSmallest = 0;
        int n = nums.length;
        int[] nse = new int[n];
        int[] psee = new int[n];
        nse = findnse(nums);
        psee = findpse(nums);
        for(int i=0;i<n;i++) {
            int left = i-psee[i];
            int right = nse[i]-i;
            sumSmallest += (long) right * left * nums[i];
        }

        int[] nle = new int[n];
        int[] ple = new int[n];
        nle = findnle(nums);
        ple = findple(nums);
        for(int i=0;i<n;i++) {
            int left = i-ple[i];
            int right = nle[i]-i;
            sumLargest  += (long) right * left * nums[i];
        }

        return(sumLargest - sumSmallest);
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
            while(!st.isEmpty() && arr[st.peek()] > arr[i]){
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

    int[] findnle(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] nle = new int[n];
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && arr[st.peek()] <= arr[i]) { 
                st.pop();
            }

            if(st.isEmpty()) {
                nle[i] = n;
            }else {
                nle[i] = st.peek();
            }

            st.push(i); 
        }

        return nle;
    }

    int[] findple(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] plee = new int[n];
        for(int i=0;i<n;i++) {
            while(!st.isEmpty() && arr[st.peek()] < arr[i]){
                st.pop();
            }

            if(st.isEmpty()) {
                plee[i] = -1;
            }else {
                plee[i] = st.peek();
            }

            st.push(i);
        }
        return plee;
    }
}