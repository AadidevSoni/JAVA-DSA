class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<Pair> queue = new LinkedList<>();
        Set<String> set = new HashSet<String>();
        for(String w: wordList) {
            set.add(w);
        }
        queue.add(new Pair(beginWord,1));
        set.remove(beginWord);
        while(!queue.isEmpty()) {
            String w = queue.peek().word;
            int l = queue.peek().length;
            queue.remove();
            if(w.equals(endWord) == true) {
                return l;
            }
            for(int i=0;i<w.length();i++) {
                for(char c = 'a';c <= 'z';c++) {
                    char[] charArray = w.toCharArray();
                    charArray[i] = c;
                    String newWord = new String(charArray);
                    if(set.contains(newWord) == true) {
                        queue.add(new Pair(newWord,l+1));
                        set.remove(newWord);
                    }
                }
            }
        }
        return 0;
    }
}

class Pair {
    String word;
    int length;
    Pair(String word, int length) {
        this.word = word;
        this.length = length;
    }
}