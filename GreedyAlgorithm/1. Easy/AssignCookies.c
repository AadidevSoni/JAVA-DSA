package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] S = {1,3,6,1,2,5,2};
		int[] G = {1,4,2,6,4};
		
		int n = findContentChildren(G,S);
		
		System.out.println("Number of content children: " + n);
		
		
	}
	
    public static int findContentChildren(int[] g, int[] s) {
        int G = g.length;
        int S = s.length;

        Arrays.sort(g);
        Arrays.sort(s);

        int p1 = 0;
        int p2 = 0;

        while(p1 < G && p2 < S) {
            if(s[p2] >= g[p1]) {
                p1++;
            }
            p2++;
        }

        return p1;
    }
	
 
}

