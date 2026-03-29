package main;

import java.util.Arrays;
import java.util.Comparator;

import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		int[] bt = {4,3,7,1,2};
		Arrays.sort(bt);
		int t = 0;
		int wait = 0;
		int n = bt.length;
		for(int i=0;i<n;i++) {
			wait += t;
			t += bt[i];
		}
		int ans = wait/n;
		System.out.println("Average waiting time: " + ans);

	}

}
