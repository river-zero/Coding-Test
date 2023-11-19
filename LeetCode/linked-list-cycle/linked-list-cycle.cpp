/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 노드가 없거나 노드가 1개인 경우
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 사이클은 항상 다음 노드가 존재
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // slow는 한 계단씩
            fast = fast->next->next;  // fast는 두 계단씩
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};