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
    int findLength(ListNode *head) {
        ListNode *temp = head;
        int length = 0;
        while(temp) {
            length++;
            temp = temp->next;
        }

        return length;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        int length = findLength(head);

        k = k%length;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = dummy;
        ListNode *fast = dummy;

        for(int i=0;i<k;i++) {
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
        
    }
};