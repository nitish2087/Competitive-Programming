// Isomorphic Strings

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
 
Constraints:
1 <= s.length <= 5 * 10^4
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (mp.get(s.charAt(i)) != null){
                if (mp.get(s.charAt(i)) == t.charAt(i)) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (mp.containsValue(t.charAt(i))) return false;
                mp.put(s.charAt(i), t.charAt(i));
            }
        }
        return true;
    }
}
