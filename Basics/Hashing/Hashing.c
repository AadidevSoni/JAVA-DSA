import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Hashing {

	public static void main(String[] args) {
		
		//Number Hashing (Usign Arrays)
		//Hashing where elements are small numbers
		int n;
		int N = 1000;
		System.out.println("Enter number of elements: ");
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		
		int arr[] = new int[n];
		for(int i=0;i<n;i++) {
			arr[i] = (int)(Math.random() * 10);
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i] + " ");
		}
		
		//Hash array
		int hash[] = new int[N];
		for(int i=0;i<n;i++) {
			hash[arr[i]] += 1;
		}
		System.out.println();
		
		for(int i=0;i<11;i++) {
			if(hash[i] > 0) {
				System.out.println("Number of " + i + ": " + hash[i]);
			}
		}
		scanner.nextLine();
		
		//Character Hashing
		
		String s;
		System.out.println("Enter a word");
		s = scanner.nextLine();
		
		int cHash[] = new int[256];
		int size = s.length();
		for(int i=0;i<size;i++) {
			cHash[s.charAt(i)] += 1;
		}
		
		for(int i=0;i<256;i++) {
			if (cHash[i] > 0) {
                System.out.println("Number of " + (char)(i) + ": " + cHash[i]);
            }
		}
		
		//Hash Maps with no collision on integers
		System.out.println("Enter number of elements: ");
		n = scanner.nextInt();
		
		int arr1[] = new int[n];
		for(int i=0;i<n;i++) {
			arr1[i] = (int)(Math.random() * 10);
		}
		
		HashMap<Integer, Integer> freq = new HashMap<>();
		for (int num : arr1) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
		
		for(int i=0;i<n;i++) {
			System.out.print(arr1[i] + " ");
		}
		
		System.out.println("\nFrequencies using HashMap:");
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            System.out.println("Number " + entry.getKey() + ": " + entry.getValue());
        }
        scanner.nextLine();
        
        //Hash Maps no collision on chaarcters
        System.out.println("Enter a word: ");
        s = scanner.nextLine();
        size = s.length();
        
        HashMap<Character, Integer> frequency = new HashMap<>();
        for (char ch : s.toCharArray()) {
            frequency.put(ch, frequency.getOrDefault(ch, 0) + 1);
        }
        
        System.out.println("\nCharacter Frequencies:");
        for (Map.Entry<Character, Integer> entry : frequency.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
	}

}
