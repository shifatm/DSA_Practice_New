//Used two pointer technique
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Why move fast by 2 and slow by 1?
//So that the distance between fast and slow reduces in each step by 1.
//If we move fast by let's say 3 steps at once, abd right now the distance
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow, *fast = head;
        while(slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
               return true; 
            }
        }
        return false;
    }
};
