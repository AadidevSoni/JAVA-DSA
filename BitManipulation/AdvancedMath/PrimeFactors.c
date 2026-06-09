package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 30;
		List<Integer> divisors = new ArrayList<>();
		
		for(int i=1;i<=Math.sqrt(n);i++) {
			if(n%i == 0) {
				if(isPrime(i)) {
					divisors.add(i);
				}
				if(n/i != i) {
					if(isPrime(n/i)) {
						divisors.add(n/i);
					}
				}
			}
		}
		
		Collections.sort(divisors);
		System.out.print("Prime Factors of " + n + ": ");
		for(int num: divisors) {
			System.out.print(num + " ");
		}
		
		
    }
	
	public static boolean isPrime(int num) {
		if(num < 2) {
			return false;
		}
		for(int i=2;i*i<=num;i++) {
			if(num%i == 0) {
				return false;
			}
		}
		return true;
	}
	
}
	
//Better 

package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 780;
		Set<Integer> pf = new HashSet<>();
	
		for(int i=2;i<=n;i++) {
			if(n%i == 0) {
				pf.add(i);
				while(n%i == 0) {
					n /= i;
				}
			}
		}
		System.out.print("Prime factors: ");
		
		for(int num: pf) {
			System.out.print(num + " ");
		}
		
    }
	
}
	
//Better than above as root n iteration 

package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 12;
		Set<Integer> pf = new HashSet<>();
	
		for(int i=2;i*i<=n;i++) { //Now it wont give the number itself if it is prime
			if(n%i == 0) {
				pf.add(i);
				while(n%i == 0) {
					n /= i;
				}
			}
		}
		System.out.print("Prime factors: ");
		if(n != 1) {
			pf.add(n);
		}
		
		for(int num: pf) {
			System.out.print(num + " ");
		}
		
    }
	
}
	




