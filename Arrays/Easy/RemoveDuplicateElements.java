import java.util.Arrays;

public class RemoveDuplicateElements {

	public static void main(String[] args) {
		
		int[] nums = {1,1,2,2,2,3,3,4,5,6,6,7};
		
        int n = nums.length;
        int i=0;
        for(int j=i+1;j<=n-1;j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        int k = i+1;
        for(int x=0;x<n;x++) {
        	if(x < k) {
        		continue;
        	}else {
        		nums[x] = -1;
        	}
        }
        
        System.out.println("Number of non repeating elements: " + k);
        System.out.print("Non repeating array: ");
        System.out.println(Arrays.toString(nums));

	}

}
