class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int[] arr = new int[n+1];
        int low = 0;
        int high = n;
        int ctr = 0;
        for(char c: s.toCharArray()) {
            if(c == 'I') {
                arr[ctr] = low++;
            }else {
                arr[ctr] = high--;
            }
            ctr++;
        }
        arr[n] = high;
        return arr;
    }
}