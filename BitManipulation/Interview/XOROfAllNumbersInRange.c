package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 10;
		System.out.println("XOR of all numbers from 1 to " + n + ": ");
		if(n%4 == 1) {
			System.out.println("1");
		}else if(n%4 == 2) {
			System.out.println(n+1);
		}else if(n%4 == 3) {
			System.out.println("0");
		}else {
			System.out.println(n);
		}
		
		
    }
	
}
	


 