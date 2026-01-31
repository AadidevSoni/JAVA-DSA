class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        int n = arr.length;
        int minDiff = Integer.MAX_VALUE;
        Arrays.sort(arr);

        for(int i=0;i<n-1;i++) {
            if(arr[i+1]-arr[i] < minDiff) {
                minDiff = arr[i+1]-arr[i];
            }
        }

        for(int i=0;i<n-1;i++) {
            if(arr[i+1]-arr[i] == minDiff) {
                res.add(Arrays.asList(arr[i], arr[i + 1]));
            }
        }

        return res;
    }
    
}