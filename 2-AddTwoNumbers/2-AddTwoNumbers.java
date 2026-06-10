// Last updated: 6/10/2026, 11:51:29 AM
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode referNode = new ListNode(0);
        ListNode ll = referNode;
        int sum = 0;
        while(l1 != null || l2 != null) {
            sum += ((l1 != null)? l1.val:0) + ((l2 != null)? l2.val:0);
            ll.next= new ListNode(sum%10);
            l1 = ((l1 != null)? l1.next:null);
            l2 = ((l2 != null)? l2.next:null);
            if(sum >= 10)
                sum = 1;
            else
                sum = 0;
            System.out.println(sum + " this sum  & the val is" + ll.val);
            ll = ll.next;
        }
        if(sum == 1)
            ll.next = new ListNode(1);
        return referNode.next;
    }
}