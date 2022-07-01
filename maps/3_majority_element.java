// Majority element

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

/*
Solution: 1 [using hashmap to count frequency]

class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) != null) {
                mp.put(i, mp.get(i) + 1);
            } else {
                mp.put(i, 1);
            }
        }
        final int[] majorityElement = {0};
        mp.forEach((k,v) -> {
                if ( v > Math.floor(nums.length / 2)) {
                    majorityElement[0] = k;
                }
            });
        return majorityElement[0];
    }
}

Solution 2: Using count of majorityELement within array [O(n) & O(1)]
*/

class Solution {
    public int majorityElement(int[] nums) {
        int count = 0, result = 0;
        for (int i: nums) {
            if (count == 0) result = i;
            if (i == result) count++;
            else count--;
        }
        return result;
    }
}
