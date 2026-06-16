class Solution {
    public int findMinDifference(List<String> timePoints) {
        if(timePoints.size() > 1440) { //Only 1440 unique minutes in a day
            return 0;
        }
        int[] time = new int[timePoints.size()];
        for(int i=0;i<timePoints.size();i++) {
            String t = timePoints.get(i);
            String[] parts = t.split(":");
            int hour = Integer.parseInt(parts[0]);
            int min = Integer.parseInt(parts[1]);
            int total = hour * 60 + min;
            time[i] = total;
        }
        Arrays.sort(time);
        int minDiff = Integer.MAX_VALUE;
        for(int i=0;i<time.length-1;i++) {
            minDiff = Math.min(minDiff, time[i+1]-time[i]);
        }
        // Circular difference across midnight
        minDiff = Math.min(minDiff, 1440 - time[time.length - 1] + time[0]);
        return minDiff;
    }
}