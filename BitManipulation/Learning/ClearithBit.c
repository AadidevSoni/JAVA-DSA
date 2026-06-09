package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 13; //1101
	    System.out.println(n);
	    int i = 2;
	    int x = 1 << i;
	    x = ~x;
	    n = n & x;
	    System.out.println(n); //1001
		
    }
	
}
	


