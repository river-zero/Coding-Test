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
        ListNode* temp = new ListNode(0);
        ListNode* now = temp;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                now->next = list1;
                list1 = list1->next;
            } else {
                now->next = list2;
                list2 = list2->next;
            }
            
            now = now->next;
        }
        
        if (list1 != NULL) {
            now->next = list1;
        } else {
            now->next = list2;
        }
        
        ListNode* result = temp->next;
        delete temp;
        return result;
    }
};