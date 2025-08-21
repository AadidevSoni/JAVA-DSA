public class LinearSearch {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5};
		int num = 4;
		
		int n = arr.length;
		for(int i=0;i<n;i++) {
			if(arr[i] == num) {
				System.out.println(num + " found at index " + i);
				return;
			}
		}
		System.out.println(num + "not found in the array");

	}

}

