// Last updated: 6/10/2026, 11:51:09 AM
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode list = dummy;

        ListNode head1 = list1;
        ListNode head2 = list2;

        while (head1 != null && head2 != null) {
            if (head1.val > head2.val) {
                list.next = new ListNode(head2.val);
                head2 = head2.next;
            } else if (head1.val < head2.val) {
                list.next = new ListNode(head1.val);
                head1 = head1.next;
            } else {
                list.next = new ListNode(head1.val);
                list = list.next;
                list.next = new ListNode(head2.val);
                head1 = head1.next;
                head2 = head2.next;
            }
            list = list.next; // Move the list pointer to the next node
        }

        // Handle remaining elements in list1 or list2
        if (head1 != null) {
            list.next = head1;
        }
        if (head2 != null) {
            list.next = head2;
        }

        return dummy.next;
    }
}