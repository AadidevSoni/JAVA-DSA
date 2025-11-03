package Strings;

public class RotateString {

	public static void main(String[] args) {
		
		String s = "abcde";
		String goal = "eabcd";
		boolean res = isRotatable(s,goal);
		System.out.println(res);

	}
	
	public static boolean isRotatable(String s, String goal) {
		if(s.length() != goal.length()) return false;

        if((s+s).contains(goal)){
            return true;
        }else {
            return false;
        }
	}

}
