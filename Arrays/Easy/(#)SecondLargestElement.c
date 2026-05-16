public class SecondLargestElement {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,10,6,7,8,9};
		
		int largest = Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++) {
			if(arr[i] > largest) {
				largest = arr[i];
			}
		}
		int secondLargest = Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++) {
			if(arr[i] > secondLargest && arr[i] != largest) {
				secondLargest = arr[i];
			}
		}
		System.out.println(secondLargest); 

	}

}