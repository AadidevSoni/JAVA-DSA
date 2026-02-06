class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int a: asteroids) {
            if(a > 0) {
                st.push(a);
            }else {
                //Keep destorying previous asteroifd
                while(!st.isEmpty() && st.peek() > 0 && st.peek() < Math.abs(a)) {
                    st.pop();
                }
                //Current asteroid destoyed
                if(!st.isEmpty() && st.peek() == Math.abs(a)) {
                    st.pop();
                }else if(st.isEmpty() || st.peek() < 0) { //No positive asteroids before or empty stack
                    st.push(a);
                }
            }
        }
        int n = st.size();
        int[] arr = new int[n];
        for(int i=n-1;i>=0;i--) {
            arr[i] = st.pop();
        }
        return arr;
    }
}