
public class FindNumberThatAppearsOnceAndOthersTwice {

	public static void main(String[] args) {
		
		int[] nums = {1,1,2,2,3,4,4};
		
		int result = 0;
        for(int n: nums) {
            result ^= n;
        }
        
        System.out.println(result);

	}

}

