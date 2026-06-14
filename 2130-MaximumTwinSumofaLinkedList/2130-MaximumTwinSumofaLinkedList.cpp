// Last updated: 6/14/2026, 5:31:48 PM
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
13        int pairSum(ListNode* head) {
14        ListNode * curr = head;
15        long long n = 0 , mx = 0;
16        stack<long long> s;
17        while(curr != nullptr){
18          n++;
19          s.push(curr->val);
20          curr = curr->next;
21        }
22        curr = head;
23        for(int i = 1; i <= n/2; i++) {
24            mx = max(s.top()+curr->val ,mx);
25            s.pop();
26            curr = curr->next;
27        }             
28        return mx;
29    }
30};