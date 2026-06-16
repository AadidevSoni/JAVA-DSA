class Solution {
    public int addDigits(int num) {
        int sum = num;
        while(sum >= 10) {
            int numb = sum;
            sum = 0;
            while(numb > 0) {
                sum += numb%10;
                numb /= 10;
            }
        }
        return sum;
    }
}