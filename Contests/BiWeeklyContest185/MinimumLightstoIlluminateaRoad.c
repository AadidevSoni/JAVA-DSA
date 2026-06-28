class Solution {
  public int minLights(int[] lights) {
    int n = lights.length;

    int[] diff = new int[n + 1];

    boolean[] visible = new boolean[n];

    for (int i = 0; i < n; i++) {
      int v = lights[i];
      if (v > 0) {
        int left = Math.max(0, i - v);
        int right = Math.min(n - 1, i + v);
        diff[left]++;
        if (right + 1 < n) {
          diff[right + 1]--;
        }
      }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
      index += diff[i];
      visible[i] = index > 0;
    }
    int res = 0;
    int ind = 0;
    while (ind < n) {
      if (visible[ind]) {
        ind++;
        continue;
      }
      int length = 0;
      while (ind < n && !visible[ind]) {
        length++;
        ind++;
      }
      res += (length + 2) / 3;
    }
    return res;
  }
}