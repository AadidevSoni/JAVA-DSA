class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int res = -1;
        int n = words.length;
        int c = 0;
        for(int i=startIndex;c < n;i++) {
            int index = i % n;
            if(words[index].equals(target)) {
                res = c;
                break;
            }
            c++;
        }
        int d = 0;
        for(int i=startIndex;d < n;i--) {
            int index = (i+n)%n;
            if(words[index].equals(target)) {
                res = Math.min(c,d);
                return res;
            }
            d++;
        }
        return -1;
    }
}