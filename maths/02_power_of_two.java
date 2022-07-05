// Power of two

/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-2^31 <= n <= 2^31 - 1
*/

/*
Solution:

Use Log method to get it in one go as follows: 

	n = 2^x [Add log on both sides]
	logn = log(2^x)
	logn = x * log2
	x = logn / log2

Here if x is an integer, we may say that n is a power of 2.

Code:
*/

class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <=0 ) return false;
        double power = Math.log(n) / Math.log(2);
        return (power - (int) power > 0.00000000001) ? false : true;
    }
}
