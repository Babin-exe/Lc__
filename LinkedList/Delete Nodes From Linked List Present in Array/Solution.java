// Problem Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

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
    public ListNode modifiedList(int[] nums, ListNode head) {

        Set<Integer> st = new HashSet<>();
        for (int x : nums)
            st.add(x);
        ListNode auh = new ListNode(0, head);
        ListNode a = auh;

        while (a.next != null) {
            if (st.contains(a.next.val)) {
                a.next = a.next.next;
            } else {
                a = a.next;

            }
        }
        return auh.next;
    }
}
