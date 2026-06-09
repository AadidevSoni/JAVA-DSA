package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 12; //1100 to 1000 set bit
		//16 - 10000
		//15 - 01111
		
		//40 - 101000
		//39 - 100111
		
		//84 - 1010100
		//82 - 1010011
		System.out.println(n);
		n = n & n-1;
		System.out.println(n);
		
		
    }
	
}
	


