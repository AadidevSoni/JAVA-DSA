class Solution {
  public double minimumAverage(int[] nums) {
    int n = nums.length;
    List<Integer> num = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      num.add(nums[i]);
    }
    double res = 9999999.0;
    for (int j = 0; j < n / 2; j++) {
      int min = Integer.MAX_VALUE;
      int minIndex = -1;
      int max = Integer.MIN_VALUE;
      int maxIndex = -1;
      for (int i = 0; i < num.size(); i++) {
        if (num.get(i) < min) {
          min = num.get(i);
          minIndex = i;
        }
        if (num.get(i) > max) {
          max = num.get(i);
          maxIndex = i;
        }
      }
      // If we remove miinIndex first when its smaller, it shifts maxIndex
      if (minIndex > maxIndex) {
        num.remove(minIndex);
        num.remove(maxIndex);
      } else {
        num.remove(maxIndex);
        num.remove(minIndex);
      }

      double avg = (min + max) / 2.0;
      res = Math.min(res, avg);
    }
    return res;
  }
}