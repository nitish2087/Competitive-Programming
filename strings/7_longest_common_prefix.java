// Longest Common Prefix
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

/*
Solution:
Sort the array and check common prefix in first and last elements.
*/
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String lcp = "";
        if (strs == null) return lcp;
        int size = strs.length;
        if (size == 1) return strs[0];
        Arrays.sort(strs);
        for (int i = 0, j = 0; i < strs[0].length() && j < strs[size-1].length(); i+=1,j+=1) {
            if (strs[0].charAt(i) == strs[size-1].charAt(j)) {
                lcp += strs[0].charAt(i);
            } else {
                return lcp;
            }
        }
        return lcp;
    }
}
