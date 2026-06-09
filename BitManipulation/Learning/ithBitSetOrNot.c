package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 13; //1101
		int i = 2;
		if((n & (1 << i)) != 0) {
			System.out.println("Set");
		}else {
			System.out.println("Not set");
		}
		
		//OR
		n = 13;
		if(((n>>i) & 1) == 1) {
			System.out.println("Set");
		}else {
			System.out.println("Not set");
		}
		
		
    }
	
}
	


