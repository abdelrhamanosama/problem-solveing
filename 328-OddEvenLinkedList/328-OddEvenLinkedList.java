// Last updated: 6/10/2026, 11:49:19 AM
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
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode od = head , ev = head.next, headOfOdd = head, headOfEven = head.next;
        headOfOdd = od;
        headOfEven = ev;
        boolean parity = true;

        head = head.next.next;
        while(head != null){
            if(parity){
                od.next = head;
                od = od.next;
            }
            else{
                ev.next = head;
                ev = ev.next;
            }
            head = head.next;
            parity = !parity;
        }
        ev.next = null;
        od.next = headOfEven;
        // System.out.println(headOfOdd);
        return headOfOdd;
    }
}