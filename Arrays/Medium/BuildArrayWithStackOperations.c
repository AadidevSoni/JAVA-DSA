class Solution {
    public List<String> buildArray(int[] target, int n) {
        int indx = 0;
        List<String> op = new ArrayList<>();
        for(int i=1;i<=n;i++) {
            if(indx == target.length) break;
            op.add("Push");
            if(i == target[indx]) {
                indx++;
            }else {
                op.add("Pop");
            }
        }
        return op;
    }
}