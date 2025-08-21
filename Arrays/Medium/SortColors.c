package Arrays;

import java.util.Arrays;
import java.util.HashMap;

public class SortColors {

	public static void main(String[] args) {
		
		int nums[] = {0,1,2,2,1,0,0,1};
		sortColors(nums);
		System.out.println(Arrays.toString(nums));
		
		//Dutch National Flag Algorithm
		
		int nums1[] = {0,1,1,2,1,2,1,2,0,0};
		sortColors1(nums1);
		System.out.println(Arrays.toString(nums1));

	}
	
	public static void sortColors(int[] nums) {
        int freq[] = new int[3];
        for(int i=0;i<nums.length;i++) {
            freq[nums[i]]++;
        }
        int n = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<freq[i];j++) {
                nums[n] = i;
                n++;
            }
        }
    }
	
	public static void sortColors1(int[] nums) {
        int low  = 0;
        int mid = 0;
        int high = (nums.length - 1);
        while(mid <= high) {
            if(nums[mid] == 0) {
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }else if(nums[mid] == 1) {
                mid++;
            }else {
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            }

        }
    }
}
                         
