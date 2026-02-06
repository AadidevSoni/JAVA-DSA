package entity;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Practice {

	public static void main(String[] args) {
		
		int[] nums2 = {1,2,3,4,6};
		int[] nums1 = {2,3,4,6};
		
		Stack<Integer> st = new Stack<>();
        int n = nums2.length;
        int[] res = new int[n];
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && st.peek() >= nums2[i]) {
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

        for(int i=0;i<arr.length;i++) {
        	System.out.print(arr[i] + " ");
        }
		
	}

}
