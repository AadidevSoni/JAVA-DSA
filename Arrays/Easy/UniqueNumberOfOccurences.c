class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = arr.length;
        for(int i=0;i<n;i++) {
            map.put(arr[i], map.getOrDefault(arr[i],0)+1);
        }
        Set<Integer> count = new HashSet<>();
        for(int num: map.values()) {
            if(count.contains(num)) {
                return false;
            }
            count.add(num);
        }
        return true;
    }
}/