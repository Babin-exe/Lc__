// Problem Link : https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* solve(ListNode* p) {
        if (p == NULL || p->next == NULL) {
            return p;
        }
        ListNode * head = solve(p->next);
        p->next->next = p;
        p->next = NULL;


        return head;
    }
    ListNode* reverseList(ListNode* head) { return solve(head); }
};
