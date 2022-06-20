// Convert Sorted Array to Binary Search Tree

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode createBst(int[] nums, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low)/2;
            TreeNode treeNode = new TreeNode(nums[mid]);
            treeNode.left = createBst(nums, low, mid-1);
            treeNode.right = createBst(nums, mid+1, high);
            return treeNode;
        }
        return null;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode treeNode = createBst(nums, 0, nums.length -1);
        return treeNode;
    }
}
