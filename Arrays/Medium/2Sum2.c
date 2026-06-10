class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = numbers.length;
        int[] arr = new int[2];
        for(int i=0;i<n;i++) {
            int x = numbers[i];
            int need = target-x;
            if(map.containsKey(need)) {
                int ind2 = i+1;
                int ind1 = map.get(need)+1;
                arr[0] = ind1;
                arr[1] = ind2;
                break;
            }
            map.put(x,i);
        }
        return arr;
    }
}