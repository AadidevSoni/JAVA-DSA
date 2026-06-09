package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 13; 
		int setBits = 0;
		while(n > 1) {
			if(n % 2 == 1) {
				setBits++;
			}
			n /= 2;
		}
		if(n == 1) {
			setBits++;
		}
		System.out.println("No of set bits: " + setBits);
		
		//OR
		
		n = 13; 
		setBits = 0;
		while(n > 1) {
			setBits += n&1;
			n /= 2;
		}
		if(n == 1) {
			setBits++;
		}
		System.out.println("No of set bits: " + setBits);
		
    }

    //OR

    int n = 13; 
		int count = 0;
		
		while(n != 0) {
			n = n&n-1;
			count++;
		}
		System.out.println(count);
	
}
	


