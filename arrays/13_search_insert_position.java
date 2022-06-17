// Search insert position

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

/*
Solution: use binary search
*/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int startIndex = 0, endIndex = nums.length-1;
        if (nums[startIndex] == target) return startIndex;
        if (nums[endIndex] == target) return endIndex;
        while (startIndex <= endIndex) {
            int mid = startIndex + Math.abs(startIndex - endIndex)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) endIndex = mid - 1;
            else startIndex = mid + 1;
        }
        return startIndex;
    }
}

