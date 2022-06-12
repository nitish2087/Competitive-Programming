// Palindrome number

/*
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

/*
Solution:
- Get string value of int, use string builders to compare normal and reversed string.
- iterate over copy of integer to find reverse and compare both of them.
*/

/*
1:
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        StringBuilder input = new StringBuilder();
        input.append(String.valueOf(x));
        StringBuilder revInput = new StringBuilder();
        revInput.append(input);
        revInput.reverse();
        return input.toString().equals(revInput.toString()) ? true : false;
    }
}

2.
*/

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int temp = x;
        int reverse = 0;
        while (x>0) {
            int rem = x%10;
            reverse = reverse * 10 + rem;
            x /= 10;
        }
        return temp == reverse ? true : false;
    }
}
