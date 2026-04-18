class Solution {
    public boolean checkStrings(String s1, String s2) {
        int n = s1.length();
        List<Character> s1lst1 = new ArrayList<>();
        List<Character> s2lst1 = new ArrayList<>();
        List<Character> s1lst2 = new ArrayList<>();
        List<Character> s2lst2 = new ArrayList<>();
        for(int i=0;i<n;i++) {
            if(i%2 == 0) {
                s1lst1.add(s1.charAt(i));
                s2lst1.add(s2.charAt(i));
            }else {
                s1lst2.add(s1.charAt(i));
                s2lst2.add(s2.charAt(i));
            }
        }
        Collections.sort(s1lst1);
        Collections.sort(s2lst1);
        Collections.sort(s1lst2);
        Collections.sort(s2lst2);
        if((s1lst1.equals(s2lst1)) && s1lst2.equals(s2lst2)) {
            return true;
        }else {
            return false;
        }
    }
}