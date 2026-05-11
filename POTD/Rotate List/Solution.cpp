// Problem Link : https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-11

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int len = 1;
        ListNode* tail = head;
        ListNode* front = head;

        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k == 0)
            return head;

        int taillen = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < taillen; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        tail->next = head;
        return newHead;
    }
};
