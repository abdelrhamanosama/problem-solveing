// Last updated: 6/10/2026, 11:49:34 AM
class Solution {
    public boolean isPalindrome(ListNode head) {
        StringBuilder elements = new StringBuilder();
        while(head != null) {
            elements.append(head.val);
            head = head.next;
        }
        for(int i = 0; i < elements.length()/2; i++)
        {
            if(elements.charAt(i) != elements.charAt(elements.length()-i-1))
                return false;
        } 
        return true;
    }
}