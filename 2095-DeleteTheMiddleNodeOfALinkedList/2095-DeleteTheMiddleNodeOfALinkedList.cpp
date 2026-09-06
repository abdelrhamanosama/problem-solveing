// Last updated: 9/6/2026, 2:19:32 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * curr = head , * curr2 = head , *prev = curr;
        while(curr2->next != nullptr){
          prev = curr;
          curr = curr->next;
          curr2 = curr2->next;
          if(curr2->next!=nullptr) curr2 = curr2->next;
          else break;
        }
        if(prev->next != nullptr)
            prev->next = prev->next->next;
        else {
            return nullptr;
        }      
        return head;
    }
};