import java.util.Arrays;

public class LeftRotateArrayByOnePlace {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,6,6,7};
		
		int first = arr[0];
		int n = arr.length;
		for(int i=1;i<=n-1;i++) {
			arr[i-1] = arr[i];
		}
		arr[n-1] = first;
		System.out.print("After left rotation: ");
		System.out.println(Arrays.toString(arr));

	}

}
