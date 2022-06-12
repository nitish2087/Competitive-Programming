// merge two sorted array

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

/*
Solution:
- Create an insert method which accepts head and value to be inserted.
- A while to traverse in both lists and add to resultant list comparatively.
- A while loop on each of the two given lists to add left elements.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void insertToList(ListNode result, int val) {
        ListNode temp = result;
        if (result == null) {
           result = new ListNode(val, null);
           return;
        }
        while (result.next != null) {
            result = result.next;
        }
        result.next = new ListNode(val, null);
        return;
    }
    
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null && list2 == null) return null;
        if (list2 == null) return list1;
        if (list1 == null) return list2;
        ListNode result = new ListNode(); 
        
        while (list1 != null && list2 != null) {
            ListNode temp = new ListNode();
            if (list1.val <= list2.val) {
                temp.val= list1.val;
                temp.next = list1.next;
                list1 = list1.next;
            } else {
                temp.val = list2.val;
                temp.next = list2.next;
                list2 = list2.next;
            }
            insertToList(result, temp.val);
        }
        while (list1 != null) {
            insertToList(result, list1.val);
            list1 = list1.next;
        }
        while (list2 != null) {
            insertToList(result, list2.val);
            list2 = list2.next;
        }
        result = result.next;
        return result;
    }
}
