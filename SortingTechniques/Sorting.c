package Arrays;
import java.util.ArrayList;
import java.util.Arrays;

public class Sorting {

	public static void main(String[] args) {
		
		System.out.println("SELECTION SORT"); //find minimum element and place it in order from beginning to end of array and exclude last element as sorted
		int[] arr = new int[] {5,2,3,4,1};
		int size = arr.length;
		
		selectionSort(arr,size);
		System.out.println();
		
		System.out.println("BUBBLE SORT"); //pushes the max to last index by adjacent swap and then repeat excluding the last index element each time
		
		int[] arr1 = new int[] {5,2,3,4,1};
		int size1 = arr.length;
		
		bubbleSort(arr1,size1);
		System.out.println();
		
		System.out.println("INSERTION SORT"); //takes an element and places it at the right position comparing the array by size from small to big
		
		int[] arr2 = new int[] {5,2,3,4,1};
		int size2 = arr.length;
		
		insertionSort(arr2,size2); 
		System.out.println();
		
		System.out.println("MERGE SORT"); //divide and merge
		
		int[] arr3 = new int[] {5,2,3,4,1};
		int size3 = arr.length;
		System.out.println("Before sorting: ");
		System.out.println(Arrays.toString(arr3));
		
		mergeSort(arr3,0,size3-1); 
		
		System.out.println("After sorting: ");
		System.out.println(Arrays.toString(arr3));
		

	}
	
	public static void selectionSort(int[] arr,int n) {
		
		System.out.println("Before sorting: ");
		System.out.println(Arrays.toString(arr));
		
		for(int i=0;i<=n-2;i++) { //last index will automatically be biggest therefore till n-2
			int mini = i;
			for(int j=i;j<=n-1;j++) {
				if(arr[j] < arr[mini]) {
					mini = j;
				}
			}
			int temp = arr[mini];
			arr[mini] = arr[i];
			arr[i] = temp;
		}
		
		System.out.println("After sorting: ");
		System.out.println(Arrays.toString(arr));
		
	}
	
	public static void bubbleSort(int[] arr,int n) { //step 1- 0 to n-1 then 0 to n-2 ......
		
		System.out.println("Before sorting: ");
		System.out.println(Arrays.toString(arr));
		
		for(int i=n-1;i>=1;i--) {
			for(int j=0;j<i;j++) {  //j<i as otherwise for the last index element, it will look for the next index which is not present and will give error
				if(arr[j+1]<arr[j]) {
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				} 	
			}
		}
		
		System.out.println("After sorting: ");
		System.out.println(Arrays.toString(arr));
		
	}
	
	public static void insertionSort(int[] arr,int n) { 
		
		System.out.println("Before sorting: ");
		System.out.println(Arrays.toString(arr));
		
		for(int i=0;i<=n-1;i++) { //we are first comparing array of size 1 then 2,3,4... and we sort each array as we go
			int j = i;
			while(j>0 && arr[j-1]>arr[j]) {  //j not zero as j-1 doesnt exist 
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				j--;
			}
		}
		
		System.out.println("After sorting: ");
		System.out.println(Arrays.toString(arr));
		
	}
	
	private static void merge(int[] arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>(); // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.add(arr[left]);
                left++;
            } else {
                temp.add(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.add(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.add(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }
    }

    public static void mergeSort(int[] arr, int low, int high) {
        if (low >= high) return; // when there is only one element left
        int mid = (low + high) / 2 ;
        mergeSort(arr, low, mid);  // left half
        mergeSort(arr, mid + 1, high); // right half
        merge(arr, low, mid, high);  // merging sorted halves
    }
	
	

}
