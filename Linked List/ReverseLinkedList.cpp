/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/



//Recursive Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};



//Iterative Appraoch
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nextNode = NULL;
        while(cur != NULL) {
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        head = prev;
        return head;
    }
};