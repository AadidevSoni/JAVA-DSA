class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int max = Integer.MIN_VALUE;
        int left = 0;
        int right = n-1;

        while(left < right) {
            int minHeight = Math.min(height[left],height[right]);
            int width = right - left;
            int area = minHeight * width;

            if(area > max) {
                max = area;
            }

            if(height[left] < height[right]) {
                left++;
            }else {
                right --;
            }
        }

        return max;
    }
}