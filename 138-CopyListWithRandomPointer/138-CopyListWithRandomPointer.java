// Last updated: 6/10/2026, 11:50:20 AM
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;

        // خريطة تربط القديم بالجديد
        HashMap<Node, Node> mp = new HashMap<>();

        // خطوة 1: اعمل نسخ لكل nodes (من غير random صحيح)
        Node curr = head;
        while(curr != null){
            mp.put(curr, new Node(curr.val));
            curr = curr.next;
        }

        // خطوة 2: اربط next + random للنسخ
        curr = head;
        while(curr != null){
            Node copy = mp.get(curr);
            copy.next = (curr.next == null ? null : mp.get(curr.next));
            copy.random = (curr.random == null ? null : mp.get(curr.random));
            curr = curr.next;
        }

        // الرأس الجديدة
        return mp.get(head);
    }
}
