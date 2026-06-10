// Last updated: 6/10/2026, 11:50:19 AM
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
        int i = 0;
        const int  N = 1e4;
        
        while(i<N){
            i++;
            if(head == NULL ||head->next == NULL) return 0;
            head = head->next;
            if(i >= N) return 1;
        }
        return 1;
    }
};