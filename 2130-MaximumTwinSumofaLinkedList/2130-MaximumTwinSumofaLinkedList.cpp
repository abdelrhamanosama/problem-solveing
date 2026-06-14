// Last updated: 6/14/2026, 6:06:08 PM
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
13        ListNode* reverse(ListNode* head) {
14      ListNode* prev = nullptr;
15      while(head!=nullptr){
16        ListNode* nxt = head->next;
17        head->next = prev;
18        prev = head;
19        head = nxt;
20      }
21      return prev;
22    }
23    int pairSum(ListNode* head) {
24        ListNode * curr = head , * curr2 = head;
25        int n = 0 , mx = 0;
26        
27        while(curr2 != nullptr){
28          curr = curr->next;
29          curr2 = curr2->next->next;
30        }
31        curr = reverse(curr);   
32        while(curr!=nullptr){
33          mx = max(head->val + curr->val, mx);
34          head = head->next;
35          curr = curr->next;
36        }
37        return mx;
38    }
39};