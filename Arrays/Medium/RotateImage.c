package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute Force
		
		int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
		
		int n = matrix.length;
        int temp[][] = new int[n][n];
        
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix[i][j] + " ");
        	}
        	System.out.println();
        }
		System.out.println();

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                temp[j][(n-1)-i] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                matrix[i][j] = temp[i][j];
            }
        }
        
        System.out.println("Rotated Matrix: ");
        
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix[i][j] + " ");
        	}
        	System.out.println();
        }
        System.out.println();
        
        //Optimal - Transposing the matrix and reversing each row
        
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix[i][j] + " ");
        	}
        	System.out.println();
        }
		System.out.println();
        
        int len = matrix.length;

        for(int i=0;i<len;i++) {
            for(int j=i;j<len;j++) {
                int tem = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tem; 
            }
        }

        for(int i=0;i<len;i++) {
            for(int j=0;j<len/2;j++) {
                int tem = matrix[i][j];
                matrix[i][j] = matrix[i][len - 1 - j];
                matrix[i][len - 1 - j] = tem;
            }
        }
        
        System.out.println("Rotated Matrix: ");
        
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		System.out.print(matrix[i][j] + " ");
        	}
        	System.out.println();
        }
        
	}
	
}
