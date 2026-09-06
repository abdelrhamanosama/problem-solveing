// Last updated: 9/6/2026, 2:19:21 PM
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
        ListNode* reverse(ListNode* head) {
      ListNode* prev = nullptr;
      while(head!=nullptr){
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
      }
      return prev;
    }
    int pairSum(ListNode* head) {
        ListNode * curr = head , * curr2 = head;
        int n = 0 , mx = 0;
        
        while(curr2 != nullptr){
          curr = curr->next;
          curr2 = curr2->next->next;
        }
        curr = reverse(curr);   
        while(curr!=nullptr){
          mx = max(head->val + curr->val, mx);
          head = head->next;
          curr = curr->next;
        }
        return mx;
    }
};