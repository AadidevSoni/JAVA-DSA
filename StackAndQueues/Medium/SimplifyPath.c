class Solution {
    public String simplifyPath(String path) {
        Stack<String> st = new Stack<>();
        String[] parts = path.split("/");
        for(String s: parts) {
            if(s.equals("") || s.equals(".")) {
                continue;
            }
            if(s.equals("..")) {
                if(!st.isEmpty()) {
                    st.pop();
                }
            }else {
                st.push(s);
            }
        }
        if(st.isEmpty()) {
            return "/";
        }
        StringBuilder res = new StringBuilder();
        for(String str: st) {
            res.append("/").append(str);
        }
        return res.toString();
    }
}