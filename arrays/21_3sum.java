// 3Sum

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null) return null;
        int n = nums.length;
        Arrays.sort(nums);
        if (n >= 3 && nums[0] == nums[n-1]) {
            if (nums[0] == 0) return Arrays.asList(Arrays.asList(0,0,0));
            else return Arrays.asList();
        }
        Set<List<Integer>> result = new HashSet<>(nums.length);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1, k = n - 1; j < k;) {
                if (nums[j] + nums[k] == (-1)*nums[i]) {
                    List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k]);
                    Collections.sort(temp);
                    result.add(temp);
                    if (nums[j] < nums[k]) k--; else j++;
                }
                if (nums[j] + nums[k] > -1*nums[i]) k--;
                if (nums[j] + nums[k] < -1*nums[i]) j++;
            }
        }
        List<List<Integer>> ans = new ArrayList<>(result.size());
        ans.addAll(result);
        return ans;
    }
}
