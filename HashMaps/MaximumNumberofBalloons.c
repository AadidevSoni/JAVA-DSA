class Solution {
  public int maxNumberOfBalloons(String text) {
    Map<Character, Integer> map = new HashMap<>();
    int n = text.length();
    for (int i = 0; i < n; i++) {
      char c = text.charAt(i);
      map.put(c, map.getOrDefault(c, 0) + 1);
    }
    int count = 0;
    boolean flag = true;
    while (flag) {
      if (!map.containsKey('b') || !map.containsKey('a') ||
          !map.containsKey('l') || !map.containsKey('o') ||
          !map.containsKey('n')) {
        break;
      }
      if (map.get('b') > 0 && map.get('a') > 0 && map.get('l') >= 2 &&
          map.get('o') >= 2 && map.get('n') > 0) {
        count++;
        map.put('b', map.get('b') - 1);
        map.put('a', map.get('a') - 1);
        map.put('l', map.get('l') - 2);
        map.put('o', map.get('o') - 2);
        map.put('n', map.get('n') - 1);
      } else {
        break;
      }
    }
    return count;
  }
}