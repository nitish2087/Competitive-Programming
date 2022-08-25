// Remove duplicates from sorted array

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
Solution:
- With the help of auxiliary array, pick unique elements.
- Find duplicated and replace them using two pointer in the same array (in-place).
*/

/*
1. [Better runtime]
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return 1;
        int i = 0, lastIndex = 0;
        int[] temp = new int[nums.length]; 
        for (int k = 1; k < nums.length; k+=1) {
            if (nums[k-1] == nums[k]) {
                i += 1;
            } else {
                if(k-1-i >=0){
                    temp[k-1-i] = nums[k-1];
                    lastIndex += 1;
                }
            }
        }
        if (lastIndex > 0 && temp[lastIndex-1] != nums[nums.length-1]) {
            temp[lastIndex] = nums[nums.length-1];
        }
        if (nums.length - i == 1) return 1; 
        for (int j = 0; j < nums.length; j+=1) nums[j] = temp[j];
        return nums.length - i;
    }
}
2. Using tree set

class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer> st = new TreeSet<Integer>();
        st.addAll(IntStream.of(nums).boxed().collect(Collectors.toList()));
        Iterator<Integer> it = st.iterator();
        int i = 0;
        while (it.hasNext()) {
            nums[i++] = it.next();
        }
        return st.size();
    }
}

3. [Better space]
*/
class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int result = 0;
        int j = 0;
        for (int i = 1; i< n; i+=1) {
            if (nums[i] == nums[i-1]) {
                nums[i-1] = -99999;
                result+=1;
            }
        }
        for (int i = 0; i < n; i+=1){
            if (nums[i] == -99999) {
                j = i;
                while(j < n-1 && nums[j] == -99999) {
                    j+=1;
                }
                if (nums[j] != -99999) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return n - result; 
    }
}



