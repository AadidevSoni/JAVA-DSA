//Brute force
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int sum = 0;
        int n = arr.length;
        int mod = (int) (1000000000 + 7);
        for(int i=0;i<n;i++) {
            int min = arr[i];
            for(int j=i;j<n;j++) {
                min = Math.min(min, arr[j]);
                sum += min%mod;
            }
        }
        return sum;
    }
}

//Optimal 
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] nse = new int[n]; //for an index nse[i] stores the index of next smaller element
        int[] psee = new int[n];
        nse = findNSE(arr);
        psee = findPSEE(arr);
        long MOD = 1_000_000_007;
        long total = 0;
        for(int i=0;i<n;i++) {
            long left = i - psee[i];
            long right = nse[i] - i;
            long contrib = (left * right) % MOD;
            contrib = (contrib * arr[i]) % MOD;
            total = (total + contrib) % MOD;
        }
        return (int)total;
    }

    int[] findNSE(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] nse = new int[n];
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]) { //compare with the value not the index
                st.pop();
            }

            if(st.isEmpty()) {
                nse[i] = n;
            }else {
                nse[i] = st.peek();
            }

            st.push(i); //push the index not the element
        }

        return nse;
    }

    int[] findPSEE(int[] arr) {
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
}