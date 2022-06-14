// Implement indexOf() or strStr()

/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

/*
Solution: use two variables to maintain maximum window size and minimum index, iterater over haystack string and compare needle for window.
*/

class Solution {
    public static int strStr(String haystack, String needle) {
        if (needle == null || needle == "") {
            return 0;
        }
        if (needle.length() > haystack.length()) {
            return -1;
        }
        int ws = 0, j = 0;
        int maxWs = 0, minIndex = -1, marker = 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (j < needle.length() && needle.charAt(j) == haystack.charAt(i)) {
                j++;
                ws++;
                if (marker == 0) minIndex = i;
                marker = 1;
                if (ws == needle.length()) {
                    maxWs = ws;
                    break;
                }
            } else {
                marker = 0;
                j = 0;
                i-=ws;
                ws = 0;
            }
        }
        return (maxWs > 0 && maxWs == needle.length() && minIndex != -1) ? minIndex : -1;
    }
}
