// Last updated: 6/15/2026, 3:43:16 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* deleteMiddle(ListNode* head) {
14        ListNode * curr = head , * curr2 = head , *prev = curr;
15        while(curr2->next != nullptr){
16          prev = curr;
17          curr = curr->next;
18          curr2 = curr2->next;
19          if(curr2->next!=nullptr) curr2 = curr2->next;
20          else break;
21        }
22        if(prev->next != nullptr)
23            prev->next = prev->next->next;
24        else {
25            return nullptr;
26        }      
27        return head;
28    }
29};