package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		String bin = convertToBin(n);
		System.out.println(n + " = " + bin);
		scanner.nextLine();
		
		String s = scanner.nextLine();
		int dec = convertToDec(s);
		
		System.out.println(s + " = " + dec);
		
	}
	
	public static String convertToBin(int n) {
		String res = "";
		while(n > 0) {
			if(n % 2 == 1) {
				res += "1";
			}else {
				res += "0";
			}
			n /= 2;
		}
		String reversed = reverse(res);
		return reversed;
	}
	
	public static String reverse(String s) {
		int n = s.length();
		String st = "";
		for(int i=0;i<n;i++) {
			st += s.charAt(n-i-1);
		}
		return st;
	}
	
	public static int convertToDec(String s) {
		int res = 0;
		int n = s.length();
		int p = 1;
		for(int i=n-1;i>=0;i--) {
			if(s.charAt(i) == '1') {
				res += p;
			}
			p *= 2;
		}
		return res;
	}
	
	public static int Pow(int n, int p) {
		int res = 1;
		for(int i=0;i<p;i++) {
			res *= n;
		}
		return res;
	}

}
