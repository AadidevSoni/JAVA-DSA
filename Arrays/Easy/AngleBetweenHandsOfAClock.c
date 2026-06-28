class Solution {
    public double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes; //360 degree in 60 minutes
        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes; //360 in 12 hours and moves as minute hand movyes

        double diff = Math.abs(hourAngle - minuteAngle);

        return Math.min(diff, 360.0 - diff);
    }
}