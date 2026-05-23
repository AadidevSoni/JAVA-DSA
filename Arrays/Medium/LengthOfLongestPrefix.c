class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<String> set = new HashSet<>();
        for(int num: arr1) {
            String s = Integer.toString(num);
            StringBuilder pref = new StringBuilder();
            for(int i=0;i<s.length();i++) {
                pref.append(s.charAt(i));
                set.add(pref.toString());
            }
        }

        int ans = 0;
        for(int num: arr2) {
            String s2 = Integer.toString(num);
            StringBuilder pref = new StringBuilder();
            for(int i=0;i<s2.length();i++) {
                pref.append(s2.charAt(i));
                if(set.contains(pref.toString())) {
                    ans = Math.max(ans,i+1);
                }
            }
        }

        return ans;
    }
}