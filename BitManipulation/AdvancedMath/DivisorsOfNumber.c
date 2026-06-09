package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 36;
		List<Integer> divisors = new ArrayList<>();
		
		for(int i=1;i<=Math.sqrt(n);i++) {
			if(n%i == 0) {
				divisors.add(i);
				if(n/i != i) {
					divisors.add(n/i);
				}
			}
		}
		
		Collections.sort(divisors);
		System.out.print("Divisors of " + n + ": ");
		for(int num: divisors) {
			System.out.print(num + " ");
		}
		
		
    }
	
}
	


