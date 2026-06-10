class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if(words.length != pattern.length()) {
            return false;
        }
        Map<Character, String> map = new HashMap<>();
        Map<String, Character> map1 = new HashMap<>();
        for(int i=0;i<pattern.length();i++) {
            String w = words[i];
            char c = pattern.charAt(i);
            if(map.containsKey(c)) {
                if(!map.get(c).equals(w)) {
                    return false;
                }
            }else {
                map.put(c,w);
            }

            if(map1.containsKey(w)) {
                if(map1.get(w) != c) {
                    return false;
                }
            }else {
                map1.put(w,c);
            }
        }
        return true;
    }
}