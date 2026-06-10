// Last updated: 6/10/2026, 11:50:15 AM
// import java.util.*;

class Solution {
    public ListNode insertionSortList(ListNode head) {
        ArrayList<Integer> arr = new ArrayList<>();
        ListNode curr = head;

        while (curr != null) {
            arr.add(curr.val);
            curr = curr.next;
        }

        Collections.sort(arr);

        curr = head;
        int i = 0;
        while (curr != null) {
            curr.val = arr.get(i++);
            curr = curr.next;
        }

        return head;
    }
}
