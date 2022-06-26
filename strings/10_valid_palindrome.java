// Valid palindrome

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

class Solution {
    public boolean isPalindromeString(StringBuilder s, int i, int j) {
        if (i >= j) return true;
        if (s.charAt(i) != s.charAt(j)) return false;
        return isPalindromeString(s, i+1, j-1);
    }
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        ArrayList<Character> alphabets = new ArrayList<>(26);
        for (int i = 97; i <= 122; i++) {
            alphabets.add((char)i);
        }
        for (int i = 48; i <= 57; i++) {
            alphabets.add((char)i);
        }
        
        StringBuilder palindrome = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (alphabets.contains(c)) {
                palindrome.append(c);
            }
        }
        if (palindrome == null || palindrome.toString() == "") return true;
        return isPalindromeString(palindrome, 0, palindrome.length() - 1);
    }
}
