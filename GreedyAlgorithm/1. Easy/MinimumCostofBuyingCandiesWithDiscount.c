class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int n = cost.length;
        int cnt = 0;
        int total = 0;
        for(int i=n-1;i>=0;i--) {
            cnt++;
            if(cnt == 3) {
                cnt = 0;
                continue;
            }
            total += cost[i];
        }
        return total;
    }
}