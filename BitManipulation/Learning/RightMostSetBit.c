package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int num = 12; //1100 get rightmost set bit;
		int x = num & (num-1); //1011
		int res = x ^ num; //0100
		System.out.println(res);
		
		
    }
	
}
	


