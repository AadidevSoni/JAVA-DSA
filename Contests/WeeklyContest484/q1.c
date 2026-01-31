/*
Q1. Count Residue Prefixes
Solved
Easy
3 pt.
You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters in the prefix is equal to len(prefix) % 3.

Return the count of residue prefixes in s.

A prefix of a string is a non-empty substring that starts from the beginning of the string and extends to any point within it.
 

Example 1:

Input: s = "abc"

Output: 2

Explanation:​​​​​​​

Prefix "a" has 1 distinct character and length modulo 3 is 1, so it is a residue.
Prefix "ab" has 2 distinct characters and length modulo 3 is 2, so it is a residue.
Prefix "abc" does not satisfy the condition. Thus, the answer is 2.
*/

class Solution {
    public int residuePrefixes(String s) {
        int n = s.length();
        int unique = 0;
        int[] freq = new int[26];
        int count = 0;
        for(int i=0;i<n;i++) {
            int idx = s.charAt(i) - 'a';
            if(freq[idx] == 0) {
                unique++;
            }
            freq[idx]++;

            int len = i+1;
            if(unique == len%3) {
                count++;
            }
        }
        return count;
    }
}