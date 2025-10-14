package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
     
		int[] coins = {1,2,5,10,20,50,100,500,1000};
		
		Scanner scanner = new Scanner(System.in);
		int value;
		System.out.println("Enter amount: ");
		value = scanner.nextInt();
		
		int minCoins = getMinCoins(coins, value);
		System.out.println("Min Coins = " + minCoins);
	 
	}
	
	public static int getMinCoins(int[] coins, int amount) {
		
		int remainingAmount = amount;
		int noCoins = 0;
		
		Vector<Integer> used = new Vector<>();
		
		for(int i =8;i>=0;i--) {
			while(remainingAmount >= coins[i]) {
				remainingAmount -= coins[i];
				noCoins++;
				used.add(coins[i]);
			}
		}
		
		System.out.println("Coins used: ");
		for(int i=0;i<used.size();i++) {
			System.out.print(used.elementAt(i) + " , ");
		}
		System.out.println();
		
		return noCoins;
	}
 
}

