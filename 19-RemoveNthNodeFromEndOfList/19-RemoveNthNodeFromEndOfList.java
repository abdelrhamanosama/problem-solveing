// Last updated: 6/10/2026, 11:51:11 AM
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int index = getSize(head) - n;
        if(index == 0){
            head = head.next;
            return head;
        }
        else{
            ListNode current = head;    
            while(--index > 0 && current != null){
                current = current.next;
            }
            current .next = current .next .next; 
        }
        return head;
    }
    int getSize(ListNode head){
        ListNode current = head;
        int size = 0;
        while(current != null){
            current = current.next;
            size++;
        }
        return size;
    }
}