class Solution {
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int left = 0;
        int n = s.length();
        int right = n-1;
        while(left <= right) {
            while(left < right && !isVowel(arr[left])) {
                left++;
            }
            while(right > left && !isVowel(arr[right])) {
                right--;
            }
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        return new String(arr);
    }

    public static boolean isVowel(char c) {
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            return true;
        }else {
            return false;
        }
    }
}