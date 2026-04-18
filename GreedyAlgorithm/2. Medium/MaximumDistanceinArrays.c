class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int n = arrays.size();
        int min = arrays.get(0).get(0);
        int max = arrays.get(0).get(arrays.get(0).size()-1);
        int result = 0;
        for(int i=1;i<n;i++) {
            int currMin = arrays.get(i).get(0);
            int currMax = arrays.get(i).get(arrays.get(i).size()-1);
            
            result = Math.max(result, Math.max(Math.abs(max - currMin), Math.abs(currMax - min)));
            min = Math.min(min, currMin);
            max = Math.max(max, currMax);
        }
        return result;
    }
}