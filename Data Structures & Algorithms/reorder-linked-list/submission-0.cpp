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

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next; 
        }

        ListNode* half = slow->next; 
        slow->next = nullptr; 

        ListNode* curr = nullptr; 
        while(half != nullptr) {
            ListNode* t = half->next; 
            half->next = curr; 
            curr = half; 
            half = t; 
        }

        ListNode* first = head; 
        ListNode* second = curr; 
        while(second != nullptr) {
            ListNode* t = first->next; 
            ListNode* t2 = second->next;

            first->next = second; 
            second->next = t; 

            first = t; 
            second = t2;
        }
    }
};
