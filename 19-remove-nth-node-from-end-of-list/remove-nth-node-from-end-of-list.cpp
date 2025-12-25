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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode *temp = head;
        int len = 0;

        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }

        int pos = len - n;

        if(pos == 0) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = nullptr;
            delete tmp;
            return head;
        }

        temp = head;

        while(pos>1) {
            temp = temp->next;
            pos--;
        }

        temp->next = temp->next->next;

        return head;
    }
};