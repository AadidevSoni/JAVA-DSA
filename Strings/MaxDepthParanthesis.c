package Strings;

public class MaxDepthParenthesis {

	public static void main(String[] args) {
		
		String s = "(1+(a+c) + (a-(a+(c-d))))";
		int res = maxDepth(s);
		System.out.println("Max depth: " + res);

	}
	
	public static int maxDepth(String s) {
        int currentDepth = 0;
        int maxDepth = 0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == '(') {
                currentDepth++;
                if(currentDepth > maxDepth) {
                    maxDepth = currentDepth;
                }
            }else if(s.charAt(i) == ')') {
                currentDepth--;
            }
        }
        return maxDepth;
    }

}
