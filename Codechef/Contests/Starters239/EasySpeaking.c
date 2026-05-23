import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0) {
            int t = 0;
            Set<Character> set = new HashSet<>();
    		set.add('a');
    		set.add('e');
    		set.add('i');
    		set.add('o');
    		set.add('u');
    		int N = sc.nextInt();
    		String S = sc.next();
    		int count = 0;
    		for(int i=0;i<N;i++) {
    		    if(!set.contains(S.charAt(i))) {
    		        count++;
    		    }else {
    		        count = 0;
    		    }
    		    if(count == 4) {
    		        System.out.println("Yes");
    		        t++;
    		        break;
    		    }
    		}
    		if(t == 0) {
    		    System.out.println("No");
    		}
    		t = 0;
        }
	}
}
