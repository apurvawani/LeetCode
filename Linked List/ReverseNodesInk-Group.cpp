/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/

class Solution {
public:
    
    void reverse(ListNode* start, ListNode* end) {
        ListNode* cur = start;
        ListNode* prev = NULL, *after = start->next;
        while(prev != end) {
            cur->next = prev;
            prev = cur;
            cur = after;
            if(after != NULL)
                after = after->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        ListNode* start = head, *end = head;
        int count = k-1;
        while(count--) {
            end = end->next;
            if(end == NULL)
                return head;
        }
        ListNode* newHead = reverseKGroup(end->next , k);
        reverse(start, end);
        start->next = newHead;
        return end;
    }
};