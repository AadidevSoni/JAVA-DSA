class Solution {
    public int calPoints(String[] operations) {
        int s = operations.length;
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<s;i++) {
            if(operations[i].equals("+")) {
                int top = st.pop();
                int second = st.peek();   
                int sum = top + second;
                st.push(top);            
                st.push(sum);
            }else if(operations[i].equals("C")) {
                st.pop();
            }else if(operations[i].equals("D")) {
                int top = st.pop();
                int toPush = top * 2;
                st.push(top);
                st.push(toPush);
            }else {
                st.push(Integer.parseInt(operations[i]));
            }
        }
        int sum = 0;
        while(!st.isEmpty()) {
            sum += st.pop();
        }
        return sum;
    }
}