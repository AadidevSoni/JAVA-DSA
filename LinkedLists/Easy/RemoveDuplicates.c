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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        HashSet<Integer> set = new HashSet<>();
        while(curr != null) {
            if(set.contains(curr.val)) {
                prev.next = curr.next;
            }else {
                set.add(curr.val);
                prev = curr;
            }
            curr = curr.next;
        }
        return head;
    }
}