class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>();
        for(int i=0;i<wordList.size();i++) {
            set.add(wordList.get(i));
        }
        Queue<List<String>> queue = new LinkedList<>();
        List<String> ls = new ArrayList<>();
        ls.add(beginWord);
        queue.add(ls);
        int level = 0;
        List<String> usedOnLevel = new ArrayList<>();
        usedOnLevel.add(beginWord);
        List<List<String>> ans = new ArrayList<>();

        while(!queue.isEmpty()) {
            List<String> res = queue.poll();
            if(res.size() > level) {
                level++;
                for(String s: usedOnLevel) {
                    set.remove(s);
                }
            }
            String currentWord = res.get(res.size() - 1);
            if(currentWord.equals(endWord) == true) {
                if(ans.size() == 0) {
                    ans.add(res);
                }else if(ans.get(0).size() == res.size()) {
                    ans.add(res);
                }
            }
            for(int i = 0;i<currentWord.length();i++) {
                for(char ch = 'a';ch <= 'z';ch++) {
                    char[] charArray = currentWord.toCharArray();
                    charArray[i] = ch;
                    String newWord = new String(charArray);
                    if(set.contains(newWord) == true) {
                        res.add(newWord);
                        List<String> temp = new ArrayList<>(res);
                        queue.add(temp);
                        usedOnLevel.add(newWord);
                        res.remove(res.size() - 1);
                    }
                }
            }
        }
        return ans;
    }
}