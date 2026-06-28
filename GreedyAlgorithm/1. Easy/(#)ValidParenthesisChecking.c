package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Parenthesis Checking without *
     
		Scanner scanner = new Scanner(System.in);
		String s = "";
		
		System.out.println("Enter brackets: ");
		s = scanner.nextLine();
		
		int cnt = 0;
		int n = s.length();
		int t = 0;
		
		for(int i=0;i<n;i++) {
			
			if(s.charAt(i) == '(') {
				cnt++;
			}else if(s.charAt(i) == ')') {
				cnt--;
			}
			
			if(cnt == -1) {
				System.out.println("Invalid!");
				t++;
				break;
			}
		}
		
		if(cnt == 0) {
			System.out.println("Valid!");
		}
		if(cnt != 0 && t == 0){
			System.out.println("Invalid!");
		}
		
		// Valid Parenthesis Checking using * 
		
		int index = 0;
		int count = 0;
		boolean result = checkParanthesis(s, index, count);
		
		System.out.println("Valid paranthesis: " + result);
		
		//DP Approach will give O(N2)
		
		//Greedy approach with range 
		
		int N = s.length();
        int min = 0;
        int max = 0;
        int h = 0;

        for(int i=0;i<N;i++) {
            if(s.charAt(i) == '(') {
                min += 1;
                max += 1;
            }else if(s.charAt(i) == ')') {
                min -= 1;
                max -= 1;
            }else {
                min -= 1;
                max += 1;
            }

            if(min < 0) {
                min = 0;
            }

            if(max < 0) {
                System.out.println("False");
                h++;
                break;
            }
        }

        if(min == 0) {
        	System.out.println("True");
        }
        
        if(min != 0 && h == 0){
        	System.out.println("False");
        }
		
		
	}
	
	public static boolean checkParanthesis(String s, int index, int count) {
		if(count < 0) {
			return false;
		}
		
		if(index == s.length()) {
			return (count == 0);
		}
		
		if(s.charAt(index) == '(') {
			return checkParanthesis(s,index+1,count+1);
		}
		
		if(s.charAt(index) == ')') {
			return checkParanthesis(s,index+1,count-1);
		}
		
		//If it is an '*' trey all 3 possibilities
		return checkParanthesis(s,index+1,count+1) || checkParanthesis(s,index+1,count-1) || checkParanthesis(s,index+1,count);
	}
	

 
}

