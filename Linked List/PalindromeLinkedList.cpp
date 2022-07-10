/*
Given the head of a singly linked list, return true if it is a palindrome.


Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
 

Constraints:
The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
*/

class Solution {
public:
    
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL) { 
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverse(slow);
        slow = head;
        fast = newHead;
        while(fast->next != NULL) {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};