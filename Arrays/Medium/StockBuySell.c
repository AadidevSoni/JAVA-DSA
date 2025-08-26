package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute force
		int prices[] = {3,6,1,9,4};
		
		int max = 0;
        for(int i=0;i<prices.length;i++) {
            for(int j=i+1;j<prices.length;j++) {
                int l = prices[j] - prices[i];
                if(l > max) {
                    max = l;
                }
            } 
        }
        
        System.out.println("Max profit: " + max);
        
        //Optimal 
        
        max = 0;
        int minPrice = Integer.MAX_VALUE;
        for(int i=0;i<prices.length;i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            if(prices[i] - minPrice > max) {
                max = prices[i] - minPrice;
            }
        }
        System.out.println("Max profit: " + max);
        
	}
	

	
}
