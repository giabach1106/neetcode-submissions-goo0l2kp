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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* sec; 
        ListNode* node = nullptr;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        sec = slow->next;
        slow->next = nullptr;
        while (sec) {
            ListNode* tmp = sec->next;
            sec->next = node;
            node = sec;
            sec = tmp;
        }

        ListNode* first = head;
        sec = node;
        while(sec) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = sec->next;
            first->next = sec;
            sec->next = tmp1;
            first = tmp1;
            sec = tmp2;
        }

    }
};
