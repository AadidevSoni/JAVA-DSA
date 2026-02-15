/*
Q1. Toggle Light Bulbs
Solved
Easy
3 pt.
You are given an array bulbs of integers between 1 and 100.

There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.

For each element bulbs[i] in the array bulbs:

If the bulbs[i]th light bulb is currently off, switch it on.
Otherwise, switch it off.
Return the list of integers denoting the light bulbs that are on in the end, sorted in ascending order. If no bulb is on, return an empty list.©leetcode
*/

class Solution {
    public List<Integer> toggleLightBulbs(List<Integer> bulbs) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int n: bulbs) {
            if(!map.containsKey(n)) {
                map.put(n, 1);
            }else {
                if(map.get(n) == 1) {
                    map.put(n, 0);
                }else {
                    map.put(n, 1);
                }
            }
        }
        
        List<Integer> keys = new ArrayList<>();
        
        for (int key:map.keySet()) {
            if (map.get(key) == 1) keys.add(key);
        }
        
        return keys;
    }
}©leetcode