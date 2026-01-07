import java.util.Arrays;
class Solution {
    public void rotate(int[] nums, int k) {
        if(k>=0){
            int n = nums.length;
            k = k % n;
            
            if(k==0){
                System.out.println(Arrays.toString(nums));
                return;
            }
            reverse(nums,0,n-1);
            reverse(nums,0,k-1);
            reverse(nums,k,n-1);

            System.out.println(Arrays.toString(nums));
        }else{

        }
        
    }

    public static void reverse(int[] arr,int start,int end) {
		for(int i=start,j=end;i<j;i++,j--) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
}