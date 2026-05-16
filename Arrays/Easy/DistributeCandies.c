class Solution {
    public int distributeCandies(int[] candyType) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = candyType.length;
        for(int i=0;i<n;i++) {
            if(map.containsKey(candyType[i])) {
                map.put(candyType[i], map.get(candyType[i]) + 1);
            }else {
                map.put(candyType[i], 1);
            }
        }
        int res = 0;
        for (Integer value : map.values()) {
            if(res < n/2) {
                res++;
            }else {
                return res;
            }
        }

        return res;
    }
}