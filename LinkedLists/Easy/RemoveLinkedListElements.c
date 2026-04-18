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
    public ListNode removeElements(ListNode head, int val) {
        ListNode prev = new ListNode(-1);
        ListNode current = head;
        while(current != null) {
            if(current.val == val) {
                if(prev.val == -1) {
                    head = head.next;
                }
                prev.next = current.next;
            }else {
                prev = current;
            }
            current = current.next;
        }
        return head;
    }
}