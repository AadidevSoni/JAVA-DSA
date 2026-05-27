class Solution {
    public int passwordStrength(String password) {
        int n = password.length();
        boolean[] lowercase = new boolean[26];
        boolean[] uppercase = new boolean[26];
        boolean[] num = new boolean[10];
        boolean[] special = new boolean[4];
        int points = 0;
        for(int i=0;i<n;i++) {
            char c = password.charAt(i);
            if(c >= 'a' && c <= 'z') {
                int ind = c - 'a';
                if(!(lowercase[ind])) {
                    lowercase[ind] = true;
                    points += 1;
                }
            }else if(c >= 'A' && c <= 'Z') {
                int ind = c - 'A';
                if(!(uppercase[ind])) {
                    uppercase[ind] = true;
                    points += 2;
                }
            }else if(c >= '0' && c <= '9') {
                int ind = c-'0';
                if(!num[ind]) {
                    num[ind] = true;
                    points+= 3;
                }
            }else {
                if(c == '!' && !special[0]) {
                    special[0] = true;
                    points += 5;
                }else if(c == '@' && !special[1]) {
                    special[1] = true;
                    points += 5;
                }else if(c == '#' && !special[2]) {
                    special[2] = true;
                    points += 5;
                }else if(c == '$' && !special[3]) {
                    special[3] = true;
                    points += 5;
                }else {
                    
                }
            }
        }
        return points;
    }
}