class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for(String st: tokens) {
            if(isOp(st)) {
                int b = stack.pop();
                int a = stack.pop();
                int res = 0;
                switch(st) {
                    case "+": res = a+b; break;
                    case "-": res = a-b;break;
                    case "*": res = a*b;break;
                    case "/": res = a/b;break;
                }
                stack.push(res);
            }else {
                stack.push(Integer.parseInt(st));
            }
        }

        return stack.pop();
    }

    public boolean isOp(String st) {
        return st.equals("+") || st.equals("-") || st.equals("*") || st.equals("/");
    }
}