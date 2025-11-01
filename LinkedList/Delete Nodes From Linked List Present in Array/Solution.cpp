// Problem Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for (int x : nums)
            st.insert(x);
        ListNode* auh = new ListNode(0, head);
        ListNode* a = auh;

        while (a->next != nullptr) {
            if (st.find(a->next->val) != st.end()) {
                a->next = a->next->next;
            } else {
                a = a->next;
            }
        }
        return auh->next;
    }
};
