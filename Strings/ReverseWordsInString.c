package Strings;

public class ReverseWordsInString {

	public static void main(String[] args) {
		
		String s = "Hello ! My name is Aadidev";
		String res = reverseString(s);
		System.out.println(res);

	}
	
	public static String reverseString(String s) {
		String[] words = s.trim().split("\\s+");

        StringBuilder st = new StringBuilder();
        for(int i=(words.length-1);i>=0;i--) {
            st.append(words[i]);
            if(i>0) {
                st.append(" ");
            }
        }
        return st.toString();
	}

}
