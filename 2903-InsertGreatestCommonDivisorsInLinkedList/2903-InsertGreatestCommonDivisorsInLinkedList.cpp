// Last updated: 6/10/2026, 11:42:20 AM
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
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while(current->next != NULL){
            int val = gcd(current->val,current->next->val);
            ListNode* Node = new ListNode(val,current->next);
            current->next = Node;
            current= current->next->next;    
        }
        return head;
    }
};