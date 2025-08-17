import java.util.Stack;

public class SortStackRecursion {

	public static void main(String[] args) {
		
		Stack<Integer> st = new Stack<>();
		st.push(2);
		st.push(3);
		st.push(5);
		st.push(4);
		st.push(1);
		
		System.out.println(st);
		sortStack(st);
		System.out.println(st);

	}
	
    public static void sortStack(Stack<Integer> st) {
        if(!st.isEmpty()) {
            int top = st.pop();
            sortStack(st);
            insertSorted(st,top);
        }
    }

    public static void insertSorted(Stack<Integer> st, int ele) {
        if(st.isEmpty() || st.peek() <= ele) {
            st.push(ele);
        }else {
            int top = st.pop();
            insertSorted(st,ele);
            st.push(top);
        }
    }

}

