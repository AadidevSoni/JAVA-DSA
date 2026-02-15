class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        int n = num.length();
        for(int i=0;i<n;i++) {
            while(!st.isEmpty() && k > 0 && (st.peek()-'0') > (num.charAt(i)-'0')) {
                st.pop();
                k--;
            }
            st.push(num.charAt(i));
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.isEmpty()) {
            return "0";
        }else {
            String res = "";
            while (!st.isEmpty()) {
                res = st.pop() + res;  
            }

            // remove leading zeros
            int i = 0;
            while (i < res.length() && res.charAt(i) == '0') {
                i++;
            }

            res = res.substring(i);

            return res.equals("") ? "0" : res;
        }
    }
}