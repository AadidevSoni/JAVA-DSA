class Solution {
    public int monotoneIncreasingDigits(int n) {
        for(int i=n;i>=0;i--) {
            if(isMInc(i)) {
                return i;
            }
        }
        return -1;
    }

    public boolean isMInc(int num) {
        int prev = 9;
        while(num > 0) {
            int n = num%10;
            if(n <= prev) {
                prev = n;
            }else {
                return false;
            }
            num /= 10;
        }
        return true;
    }
}

//Optimal 

class Solution {
    public int monotoneIncreasingDigits(int n) {
        char[] arr = String.valueOf(n).toCharArray();
        int l = arr.length;
        int mark = l;
        for(int i=l-1;i>0;i--) {
            if(arr[i] < arr[i-1]) {
                arr[i-1]--;
                mark = i;
            }
        }

        for(int i=mark;i<l;i++) {
            arr[i] = '9';
        }

        return Integer.parseInt(new String(arr));
    }
}