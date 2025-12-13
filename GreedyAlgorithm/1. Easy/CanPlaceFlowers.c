class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int s = flowerbed.length;
        if(s == 1) {
            if(flowerbed[0] == 0) {
                if(n == 1 || n == 0) {
                    return true;
                }else {
                    return false;
                }
            }else {
                if(n == 0) {
                    return true;
                }else {
                    return false;
                }
            }
        }
        for(int i=0;i<s;i++) {
            if(n == 0) {
                return true;
            }
            if(i == 0) {
                if(flowerbed[i+1] == 0 && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }else if(i == s-1) {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        if(n == 0) {
            return true;
        }else {
            return false;
        }
    }
}