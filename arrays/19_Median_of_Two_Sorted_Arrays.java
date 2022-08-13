// Median of Two Sorted Arrays

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[] temp = new int[m+n];
        int low1 = 0, low2 = 0, up1 = m-1, up2 = n-1, k = 0;
        while (low1 <= up1 && low2 <= up2) {
            if (nums1[low1] <= nums2[low2]) temp[k++] = nums1[low1++];
            else temp[k++] = nums2[low2++];
        }
        while (low1 <= up1) temp[k++] = nums1[low1++];
        while (low2 <= up2) temp[k++] = nums2[low2++];
        if ((m+n) % 2 != 0) return temp[(m+n)/2];
        else return (double)(temp[((m+n)/2)-1] + temp[(m+n)/2])/2;
    }
}
