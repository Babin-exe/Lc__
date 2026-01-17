/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

function solve(p) {
    if (p == null || p.next == null) {
        return p;
    }
    let head = solve(p.next);
    p.next.next = p;
    p.next = null;
    return head;
}

var reverseList = function (head) {
    return solve(head);
};
