package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 3;
		int m = 3;
		
		//Adjacency matrix
		
		int[][] adjm = new int[n+1][n+1];
		
		adjm[1][2] = 1;
		adjm[2][1] = 1;
		
		adjm[2][3] = 1;
		adjm[3][2] = 1;
		
		adjm[1][3] = 1;
		adjm[3][1] = 1;
		
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=n;j++) {
				System.out.print(adjm[i][j] + " ");
			}
			System.out.println();
		}
		
		//Adjacency List 
		ArrayList<ArrayList<Integer>> adjl = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0;i<=n;i++) {
			adjl.add(new ArrayList<Integer>());
		}
		
		adjl.get(1).add(2); //get is the index position
		adjl.get(2).add(1);
		
		adjl.get(1).add(3);
		adjl.get(3).add(1);
		
		adjl.get(2).add(3);
		adjl.get(3).add(2);
		
		System.out.println(adjl);
		
		for (int i = 0; i < adjl.size(); i++) {
		    for (int j = 0; j < adjl.get(i).size(); j++) {
		        System.out.print(adjl.get(i).get(j) + " ");
		    }
		    System.out.println();
		}

	}
	
	
}

