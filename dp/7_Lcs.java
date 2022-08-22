// Longest Common Subsequence

/*
 Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
 */


public class Lcs {

    public static int lcsRecursion(String a, String b, int m, int n) {
        if (b == null) return 0;
        if (m == 0 || n == 0) return 0;
        int result = 0;
        if (a.charAt(m-1) == b.charAt(n-1)) {
            result += (1 + lcsRecursion(a, b, m-1, n-1));
        }
        else {
            result += Math.max(lcsRecursion(a, b, m-1, n), lcsRecursion(a, b, m, n-1));
        }
        return result;
    }

    public static int lcsMemoization(int[][] dp, String a, String b, int m, int n) {
        if (b == null) return 0;
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        if (a.charAt(m-1) == b.charAt(n-1)) {
            return dp[m][n] = 1 + lcsMemoization(dp, a, b, m-1, n-1);
        }
        return dp[m][n] = Math.max(lcsMemoization(dp, a, b, m-1, n), lcsMemoization(dp, a, b, m, n-1));
    }

    public static int lcsIterative(String a, String b, int m, int n) {
        int[][] dp = new int[m+1][n+1];
        for (int i = 0; i < m + 1; i++) dp[i][0] = 0;
        for (int j = 0; j < n + 1; j++) dp[0][j] = 0;
        
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    public static void main(String a[]) {
        String one = "wercsco";
        String two = "wrso";
        int m = one.length();
        int n = two.length();
        int[][] dp = new int[m+1][n+1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println("Using recursion: " + lcsRecursion(one, two, m, n));
        System.out.println("Using memoization: " + lcsMemoization(dp, one, two, m, n));
        System.out.println("Using iterative dp: " + lcsIterative(one, two, m, n));
    }
}
