class Solution {
  public int longestPalindrome(String s) {
    int[] freq = new int[128];

    for (char c : s.toCharArray()) {
      freq[c]++;
    }

    int res = 0;
    boolean hasOdd = false;

    for (int f : freq) {
      res += (f / 2) * 2;

      if (f % 2 == 1) {
        hasOdd = true;
      }
    }

    if (hasOdd) {
      res++;
    }

    return res;
  }
}