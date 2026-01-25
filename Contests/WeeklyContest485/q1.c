/*
Q1. Vowel-Consonant Score
Solved
Easy
3 pt.
You are given a string s consisting of lowercase English letters, spaces, and digits.

Let v be the number of vowels in s and c be the number of consonants in s.

A vowel is one of the letters 'a', 'e', 'i', 'o', or 'u', while any other letter in the English alphabet is considered a consonant.

The score of the string s is defined as follows:

If c > 0, the score = floor(v / c) where floor denotes rounding down to the nearest integer.
Otherwise, the score = 0.
Return an integer denoting the score of the string.
*/

class Solution {
    public int vowelConsonantScore(String s) {
        int n = s.length();
        int c = 0;
        int v = 0;
        int space = 0;
        char[] str = s.toCharArray();
        for(char ch: str) {
            if(!Character.isLetter(ch)) {
                continue;
            }
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            }else {
                c++;
            }
        }
        if(c == 0) {
            return 0;
        }else {
            return (int) Math.floor(v/c);
        }
        
    }
}