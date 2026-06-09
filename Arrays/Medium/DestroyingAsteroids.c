class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        int n = asteroids.length;
        Arrays.sort(asteroids);
        long m = mass;
        for(int i=0;i<n;i++) {
            if(m < asteroids[i]) {
                return false;
            }
            m += asteroids[i];
        }
        return true;
    }
}