//Brute force
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums2.length;
        int[] arr = new int[n];
        for(int i=0;i<n;i++) {
            int t = 0;
            for(int j=i+1;j<n;j++) {
                if(nums2[j] > nums2[i]) {
                    t++;
                    arr[i] = nums2[j];
                    break; 
                }
            }
            if(t == 0) {
                arr[i] = -1;
            }
        }

        int m = nums1.length;
        int[] res = new int[m];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(nums1[i] == nums2[j]) {
                    res[i] = arr[j];
                }
            }
        }

        return res;
    }
}

//Monotonic stack
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        int n = nums2.length;
        int[] res = new int[n];
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && st.peek() <= nums2[i]) { 
                st.pop();
            }

            if(st.isEmpty()) {
                res[i] = -1;
            }else {
                res[i] = st.peek();
            }

            map.put(nums2[i], res[i]);

            st.push(nums2[i]);
        }

        int m = nums1.length;
        int[] arr = new int[m];
        for(int i=0;i<m;i++) {
            arr[i] = map.get(nums1[i]);
        }

        return arr;

    }
}