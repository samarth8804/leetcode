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
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *rev = nullptr;

        while(slow != nullptr) {
            ListNode *currNext = slow->next;
            slow->next = rev;
            rev = slow;
            slow = currNext;
        }

        while(rev != nullptr) {
            if(head->val != rev->val) {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }

        return true;
    }
};