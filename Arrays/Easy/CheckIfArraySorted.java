public class CheckIfArraySorted {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,10};
		int c = 0;
		
		for(int i=0;i<(arr.length-1);i++) {
			if(arr[i] < arr[i+1]) {
				continue;
			}else {
				System.out.println("Not Sorted!");
				c++;
			}
		}
		
		if(c == 0) {
			System.out.println("Sorted");
		}

	}

}
