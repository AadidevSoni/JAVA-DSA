import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int Z = sc.nextInt();
        int cost = 0;
        if(Z < 50) {
            cost = X;
            System.out.println(cost);
        }else {
            cost += X;
            Z -= 50;
            cost += Y * Z;
            System.out.println(cost);
        }
	}
}
