class Solution {
  public int maxDistance(String moves) {
    int x = 0;
    int y = 0;
    int dash = 0;

    for (char c : moves.toCharArray()) {
      if (c == 'R') {
        x++;
      } else if (c == 'L') {
        x--;
      } else if (c == 'U') {
        y++;
      } else if (c == 'D') {
        y--;
      } else {
        dash++;
      }
    }
    return (Math.abs(x) + Math.abs(y) + dash);
  }
}