
public class FindMissingNumber {

	public static void main(String[] args) {
		
		int[] nums = {0,1,2,3,5};
		
		int s1 = 0;
		int s2 = 0;
		
		for(int i=0;i<=nums.length;i++) {
			s1 += i;
		}
		
		for(int i=0;i<nums.length;i++) {
			s2 += nums[i];
		}
		
		int result = s1-s2;
        
        System.out.println(result);

	}

}
