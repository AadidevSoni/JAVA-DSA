public class LargestElement {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,10,6,7,8,9};
		
		int largest = arr[0];
		for(int i=0;i<arr.length;i++) {
			if(arr[i] > largest) {
				largest = arr[i];
			}
		}
		System.out.println("Largest element: " + largest);

	}

}
