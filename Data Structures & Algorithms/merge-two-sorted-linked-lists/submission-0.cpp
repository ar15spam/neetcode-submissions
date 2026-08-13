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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1; 
        ListNode* b = list2; 
        ListNode dummy(0); 
        ListNode* tail = &dummy; 
        while(a != nullptr && b != nullptr) {
            if(a->val <= b->val) {
                tail->next = a; 
                a = a->next; 
            } else {
                tail->next = b; 
                b = b->next; 
            }
            tail = tail->next; 
        }

        if(a != nullptr) {
            tail->next = a; 
        } else {
            tail->next = b;
        }

        return dummy.next; 
    }
};