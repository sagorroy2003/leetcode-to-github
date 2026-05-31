/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // aita recursive vabe revers kore..
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // One node hole ba akta o na hole palindrom
        if(head == NULL || head->next == NULL){
            return true;
        }

        // have to find the middle ( using fast&slow pointer)

        ListNode* fast;
        ListNode* slow;

        fast = head ;
        slow = head;
        
        // finding the middle using fast-slow pointer 
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the second half
        ListNode* newHead = reverseList(slow);

        ListNode* p1 = head;
        ListNode* p2 = newHead;

        bool isPalindrom = true;

        while(p2 != NULL){
            if(p1->val != p2->val){
                // return false;
                isPalindrom = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        reverseList(newHead);

        // if it survive then its a palindrom 
        return isPalindrom;

    }
};