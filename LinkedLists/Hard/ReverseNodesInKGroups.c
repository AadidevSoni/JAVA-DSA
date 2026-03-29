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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode ptr = new ListNode(0);
        ptr.next = head;

        ListNode lastTail = ptr; 
        while(true) {
            ListNode kth = getKthNode(lastTail, k);
            if(kth == null) {
                break;
            }
            ListNode nextGroupHead = kth.next;
            ListNode prev = nextGroupHead;
            ListNode curr = lastTail.next;
            for(int i=0;i<k;i++) {
                ListNode temp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode temp = lastTail.next;
            lastTail.next = kth;
            lastTail = temp;
        }
        return ptr.next;
    }

    public ListNode getKthNode(ListNode lastTail, int k) {
        while(lastTail != null && k > 0) {
            lastTail = lastTail.next;
            k--;
        }
        return lastTail;
    }
}