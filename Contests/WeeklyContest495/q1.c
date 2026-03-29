/*
Q1. First Matching Character From Both Ends
Solved
Easy
3 pt.
You are given a string s of length n consisting of lowercase English letters.

Return the smallest index i such that s[i] == s[n - i - 1].

If no such index exists, return -1.

 

Example 1:

Input: s = "abcacbd"

Output: 1

Explanation:

At index i = 1, s[1] and s[5] are both 'b'.

No smaller index satisfies the condition, so the answer is 1.©leetcode
*/

class Solution {
    public int firstMatchingIndex(String s) {
        int i = 0;
        int n = s.length();
        int j = n-i-1;
        while(i <= j) {
            if(s.charAt(i) == s.charAt(j)) {
                return i;
            }
            i++;
            j--;
        }
        return -1;
    }
}©leetcode