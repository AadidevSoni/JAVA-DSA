class Solution {
    public String[] findWords(String[] words) {
        String line1 = "qwertyuiopQWERTYUIOP";
        String line2 = "asdfghjklASDFGHJKL";
        String line3 = "zxcvbnmZXCVBNM";
        List<String> lst = new ArrayList<>();
        for(String w: words) {
            char c = w.charAt(0);
            int t = 0;
            if(line1.contains(String.valueOf(c))) {
                int n = w.length();
                for(int i=1;i<n;i++) {
                    if(line1.contains(String.valueOf(w.charAt(i)))) {
                        continue;
                    }else {
                        t++;
                        break;
                    }
                }
            }else if(line2.contains(String.valueOf(c))) {
                int n = w.length();
                for(int i=1;i<n;i++) {
                    if(line2.contains(String.valueOf(w.charAt(i)))) {
                        continue;
                    }else {
                        t++;
                        break;
                    }
                }
            }else if(line3.contains(String.valueOf(c))) {
                int n = w.length();
                for(int i=1;i<n;i++) {
                    if(line3.contains(String.valueOf(w.charAt(i)))) {
                        continue;
                    }else {
                        t++;
                        break;
                    }
                }
            }
            if(t == 0) {
                lst.add(w);
            }
        }
        
        int s = lst.size();
        String[] res = new String[s];
        int i = 0;
        for(String wor: lst) {
            res[i] = wor;
            i++;
        }
        return res;
    }
}