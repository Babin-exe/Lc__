// Problem Link : https://leetcode.com/problems/reverse-linked-list/
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
    public ListNode solve(ListNode p) {
        if (p == null || p.next == null) {
            return p;
        }

        ListNode head = solve(p.next);
        p.next.next = p;
        p.next = null;
        return head;
    }

    public ListNode reverseList(ListNode head) {
        return solve(head);
    }
}
