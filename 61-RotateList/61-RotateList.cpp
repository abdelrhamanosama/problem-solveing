// Last updated: 6/10/2026, 11:50:46 AM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr ||head->next == nullptr || k == 0) return head;
        int sz = 1;
        ListNode* node = head , *cut;
        while(node->next != nullptr){
            sz++;
            node = node->next;
        }
        k %= sz;
        if(k== 0) return head;
        k = sz - k - 1;
        node->next = head;
        cut = head;
        while(k--){
            cut = cut->next;
        }
        ListNode* curr = cut->next;
        cut->next = nullptr;
        return curr;
        
    }
};