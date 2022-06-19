// Climbing stairs

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

/*
Solution:
- use recursion or dp. Similar to fibonacci problem
*/

/*
0. Recursive approach:

class Solution {
    public int fun(int n, int m) {
        if (m == n) {
            return 1;
        }
        if ((m-n) > 1) {
            return fun(n+1, m) + fun(n+2, m);
        }
        if ((m-n) > 0) {
            return fun(n+1, m);
        }
        return 0;
    }
    
    public int climbStairs(int n) {
        if (n <= 3) return n;
        return fun(0, n);
    }
}

1. dp approach:
*/


class Solution {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        int[] dp = new int[n+1];
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
