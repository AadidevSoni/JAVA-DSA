class Solution {
    public int minimumPairRemoval(int[] nums) {
        List<Integer> lst = new ArrayList<>();
        for(int x: nums) {
            lst.add(x);
        }
        int count = 0;
        int n = nums.length;
        while(!isSorted(lst)) {
            count++;
            int ind = -1;
            int min = Integer.MAX_VALUE;
            for(int i=0;i<lst.size()-1;i++) {
                int sum = lst.get(i) + lst.get(i+1);
                if(sum < min) {
                    ind = i;
                    min = sum;
                }
            }
            int merged = lst.get(ind) + lst.get(ind+1);
            lst.set(ind, merged);
            lst.remove(ind+1);
        }
        return count;
    }

    public boolean isSorted(List<Integer> arr) {
        boolean sorted = true;
        int n = arr.size();
        for(int i=0;i<n-1;i++) {
            if(arr.get(i) > arr.get(i+1)) {
                sorted = false;
            }
        }
        return sorted;
    }
}