package Strings;

import java.util.Arrays;

public class ValidAnagram {

	public static void main(String[] args) {
		
		String s = "valid";
		String t = "dilav";
		boolean res = isAnagram(s,t);
		System.out.println(res);

	}
	
	public static boolean isAnagram(String s, String t) {
		int s1 = s.length();
        int s2 = t.length();
        if(s1==s2){
            int[] arr1 = new int[26];
            int[] arr2 = new int[26];
            for(int i=0;i<s1;i++){
                arr1[(s.charAt(i) - 'a')]++;
            }
            for(int i=0;i<s2;i++){
                arr2[(t.charAt(i) - 'a')]++;
            }
            if(Arrays.equals(arr1,arr2)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
	}

}
