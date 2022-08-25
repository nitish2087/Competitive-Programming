// Merge k Sorted Lists
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null) return null;
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
        ListNode temp = new ListNode();
        ListNode result = temp;
        int j = 0;
        int cycle = lists.length;
        for (int k = 0; k < 500; k++) {
            int loop = cycle;
            while (loop > 0){
                if (lists[cycle-loop] != null) {
                    pQueue.add(lists[cycle-loop].val);
                    lists[cycle-loop] = lists[cycle-loop].next;
                }
                loop--;
            }
            if (!pQueue.isEmpty()) {
                temp.next = new ListNode(pQueue.remove(), null);
                temp = temp.next;
            }
        }
        while (pQueue.size() > 0) {
            temp.next = new ListNode(pQueue.remove(), null);
            temp = temp.next;
        }
        return result.next;
    }
}