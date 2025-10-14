package Arrays;

import java.util.*;

class Item {
	int value, weight;
	
	Item (int value, int weight) {
		this.value = value;
		this.weight = weight;
	}
}

public class Practice {
	
	public static void main(String[] args) {
     
		Item[] items = {
				new Item(100,20),
				new Item(60,10),
				new Item(100,50),
				new Item(200,50)
		};
		
		int capacity = 90;
		
		double maxValue = getMaxValue(items,capacity);
		
		System.out.println("Max value = " + maxValue);
	 
	}
	
	public static double getMaxValue(Item[] items, int capacity) {
		
		Arrays.sort(items, new Comparator<Item>() {
			public int compare(Item a, Item b) {
				double r1 = (double) a.value/a.weight;
				double r2 = (double) b.value/b.weight;
				if (r1<r2) return 1; //descending order
				else if (r1 > r2) return -1;
				else return 0;
			}
		});
		
		double totalValue = 0.0;
		int remainingWeight = capacity;
		
		for(Item item: items) {
			
			if(remainingWeight == 0) {
				break;
			}
			else if(item.weight <= remainingWeight) {
				totalValue += item.value;
				remainingWeight -= item.weight;
			}
			else {
				double fraction = (double) item.value/item.weight;
				totalValue += fraction * remainingWeight;
				remainingWeight = 0;
			}
		}
		
		return totalValue;
		
	}
 
}

