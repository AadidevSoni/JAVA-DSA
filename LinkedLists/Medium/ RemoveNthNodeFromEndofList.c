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
        int size = 0;
        ListNode temp = head;
        while(temp != null) {
            temp = temp.next;
            size++;
        }
        int pos = size - n;
        if (pos == 0) return head.next;
        ListNode curr = head;
        while(pos > 1)  {
            curr = curr.next;
            pos--;
        }
        curr.next = curr.next.next;
        return head;
    }
}