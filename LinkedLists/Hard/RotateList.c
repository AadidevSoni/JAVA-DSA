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
    public ListNode rotateRight(ListNode head, int k) {

        if(head == null || head.next == null) {
            return head;
        }

        int n = 0;
        ListNode cur = head;

        while (cur != null) {
            cur = cur.next;
            n++;
        }

        k = k%n;
        
        if(k == 0) {
            return head;
        }

        for(int i=0;i<k;i++) {
            ListNode curr = head;
            ListNode prev = null;

            while(curr.next != null) {
                prev = curr;
                curr = curr.next;
            }

            prev.next = null;
            curr.next = head;
            head = curr;
        }
        return head;
    }
}