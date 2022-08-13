// Longest Substring without repeating character

/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxWs = 0, ws = 0;
        HashMap<Character, Integer> mp = new HashMap<>(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (mp.get(s.charAt(i)) != null) {
                maxWs = ws > maxWs ? ws : maxWs;
                ws = i - mp.get(s.charAt(i)) > ws ? ws + 1 : i - mp.get(s.charAt(i));
                mp.remove(s.charAt(i));
                mp.put(s.charAt(i), i);
            } else {
                mp.put(s.charAt(i), i);
                ws++;
            }
        }
        return maxWs > ws ? maxWs : ws;
    }
}
