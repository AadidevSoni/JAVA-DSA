package Strings;

public class LargestOddNumber {

	public static void main(String[] args) {
		
		String num = "2458";
		String res = getLargest(num);
		System.out.println("Largest odd number: " + res);
	}
	
	public static String getLargest(String num) {
		for(int i=(num.length()-1);i>=0;i--) {
            char c = num.charAt(i);
            if((c-'0')%2 != 0) {
                return num.substring(0,i+1);
            }
        }
        return "";
	}

}
