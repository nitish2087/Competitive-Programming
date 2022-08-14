// Reverse integer

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned). 

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/

class Solution {
    public int reverse(int x) {
        int negative = x >= 0 ? 1 : -1;
        int n = Math.abs(x), result = 0;
        double maxValue =  (Math.pow(2, 31) -1) / 10;
        while (n > 0) {
            int rem = n % 10;
            if (result >= maxValue) return 0;
            result = result*10 + rem;
            n /= 10;
        }
        return result * negative;
    }
}
