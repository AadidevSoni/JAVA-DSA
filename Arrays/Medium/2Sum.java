import java.util.Arrays;

public class 2Sum {

	public static void main(String[] args) {
		
    //Brute Force
		int[] arr = {1,2,3,4,5};
	  int target = 9;
	  int[] res = new int[2];
	  res = twoSumBrute(arr,target);
	  System.out.println(Arrays.toString(res));

    //Hashing

	}

  public static int[] twoSumBrute(int[] nums, int target) {
    int arr[] = new int[2];

    for(int i=0;i<nums.length;i++) {
      for(int j=i+1;j<nums.length;j++) {
        if(nums[i] + nums[j] == target) {
          arr[0] = i;
          arr[1] = j;
          return arr;
        }
      }
    }
    return arr;
  }
}
