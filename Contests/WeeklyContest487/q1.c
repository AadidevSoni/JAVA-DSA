/*
Q1. Count Monobit Integers
Solved
Easy
3 pt.
You are given an integer n.

An integer is called Monobit if all bits in its binary representation are the same.

Return the count of Monobit integers in the range [0, n] (inclusive).

 

Example 1:

Input: n = 1

Output: 2

Explanation:

The integers in the range [0, 1] have binary representations "0" and "1".
Each representation consists of identical bits. Thus, the answer is 2.
*/

class Solution {
    public int countMonobit(int n) {
        int count = 0;
        for(int i=0;i<=n;i++) {
            if(monobit(i)) {
                count++;
            }
        }
        return count;
    }

    public boolean monobit(int n) {
        return(n == 0 || (n&(n+1)) == 0);
    }
}