// Container With Most Water

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/

class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxestWater = 0;
        for (int i = 0, j = n - 1; i < j;) {
            int maxWater = 0;
            //case: i, j
            int case1 = (j - i)*(Math.min(height[i], height[j]));
            if (maxWater < case1) maxWater = case1;
            
            // case i+1, j
            int case2 = (j - (i+1))*(Math.min(height[i+1], height[j]));
            if (maxWater < case2) maxWater = case2;
            
            // case i, j-1
            int case3 = (j - 1 - i)*(Math.min(height[i], height[j-1]));
            if (maxWater < case3) maxWater = case3;
            
            // case i+1, j-1
            int case4 = (j - 1 - (i+1))*(Math.min(height[i+1], height[j-1]));
            if (maxWater < case4) maxWater = case4;

            if (height[i] > height[j]) j--; else i++;
            if (maxWater > maxestWater) maxestWater = maxWater; 
        }
        return maxestWater;
    }
}
