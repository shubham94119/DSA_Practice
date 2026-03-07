/*
Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverse(slow->next);
        ListNode* temp = secondHalf;

        ListNode* firstHalf = head;

        while(temp){
            if(firstHalf->val != temp->val){
                reverse(secondHalf);
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        reverse(secondHalf);
        return true;
    }
};