class Solution {
    //ListNode head;
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int x = 0;
        int y = 0;
        int z = 1;

        while(l1 != null){
            x += z*l1.val;
            z*=10;
            l1 = l1.next;
        }

        z = 1;
        while(l2 != null){
            y += z*l2.val;
            z*=10;
            l2 = l2.next;
        }

        int sum = x + y;
        if (sum == 0) {
            return new ListNode(0);
        }
