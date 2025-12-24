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
private:
    ListNode *reverseLL(ListNode *temp,ListNode *prev) {

        if(temp == nullptr) {
            
            return prev;
        }

        ListNode *head = reverseLL(temp->next,temp);
        temp->next = prev;

        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *temp = head;
        ListNode *prev = nullptr;

        head = reverseLL(temp,prev);

        return head;
    }
};