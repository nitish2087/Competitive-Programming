// Pascal's triangle

/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/


class Solution {
    public List<List<Integer>> generate(int numRows) {
        if (numRows == 0) return new ArrayList<>(0);
        List<List<Integer>> resultList = new ArrayList<>(numRows);
        int n = 0;
        while (n < numRows) {
            List<Integer> tempResult = new ArrayList<>(n);
            int prev = 1; //nC0
            tempResult.add(prev);
            for (int j = 1; j <= n; j++) {
                int current = (prev * (n - j + 1)) / j; //// nCr = (nCr-1 * (n - r + 1))/r
                prev = current;
                tempResult.add(current);
            }
            resultList.add(tempResult);
            n++;
        }
        return resultList;
    }
}