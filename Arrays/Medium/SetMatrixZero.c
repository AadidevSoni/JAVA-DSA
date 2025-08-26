package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute Force
		
		int matrix[][] = {{1,1,1},{1,0,1},{1,1,1}};
		
		int m = matrix.length;
        int n = matrix[0].length;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    for(int a=0;a<m;a++) {
                        if(matrix[a][j] != 0) {
                            matrix[a][j] = -1;
                        }
                    }
                    for(int a=0;a<n;a++) {
                        if(matrix[i][a] != 0) {
                            matrix[i][a] = -1;
                        }
                    }
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix[i][j] + " ");
        	}
        	System.out.println();
        }
        
        //Better 
        
        System.out.println(" Better: ");
        
        int matrix1[][] = {{0,1,1},{1,1,0},{1,1,1}};
        
        m = matrix1.length;
        n = matrix1[0].length;

        int col[] = new int[n];
        int row[] = new int[m]; 

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix1[i][j] == 0) {
                    col[j] = 1;
                    row[i] = 1;
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix1[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix1[i][j] + " ");
        	}
        	System.out.println();
        }
        
        //Optimized just optimizes the space
        

	}
	

	
}
