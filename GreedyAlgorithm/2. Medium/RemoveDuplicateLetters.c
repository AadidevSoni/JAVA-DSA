class Solution {
    public String removeDuplicateLetters(String s) {
        int[] freq = new int[26];
        int[] vis = new int[26];
        Arrays.fill(freq, 0);
        Arrays.fill(vis, 0);
        for(char c: s.toCharArray()) {
            freq[c-'a']++;
        }

        Stack<Character> st = new Stack<>();
        for(char c: s.toCharArray()) {
            freq[c-'a']--;
            if(vis[c-'a'] == 1) {
                continue;
            }
            while(!st.isEmpty() && st.peek() > c && freq[st.peek()-'a'] > 0) {
                vis[st.peek() - 'a'] = 0;
                st.pop();
            }
            st.push(c);
            vis[c-'a'] = 1;
        }

        String res = "";
        for(char c: st) {
            res += c;
        }

        return res;
    }
}