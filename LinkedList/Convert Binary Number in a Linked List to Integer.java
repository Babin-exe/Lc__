// Problem link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14
class Solution {
    public int getDecimalValue(ListNode head) {

        int n = 0;
        ListNode temp = head;
        int i = 0;
        while (temp != null) {
            n++;
            temp = temp.next;
        }
        int ans = 0;
        int num = n;
        while (n > 0) {
            ans = ans + ((int) Math.pow(2, num - 1 - i) * head.val);
            head = head.next;
            i++;
            n--;
        }
        return ans;
    }
}
