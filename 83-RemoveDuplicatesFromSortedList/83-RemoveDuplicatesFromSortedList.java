// Last updated: 6/10/2026, 11:50:36 AM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = null , start = head;
        curr = start;
        while(start != null){
            ListNode x = start.next;
            while( x != null && x.val == start.val){
                x = x.next;
            }
            start.next = x;
            start = start.next;
        }
        return curr;
    }
}