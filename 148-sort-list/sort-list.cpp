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
    ListNode *mergeSortedLL(ListNode *left,ListNode *right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(left != nullptr && right != nullptr) {
            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        while(left != nullptr) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }

        while(right != nullptr) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }

        return dummy->next;
    }
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode *mergeSort(ListNode *head) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *middle = findMiddle(head);

        ListNode *right = middle->next;
        ListNode *left = head;

        middle->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        return mergeSortedLL(left,right);

        
    }
public:
    ListNode* sortList(ListNode* head) {
        
        head = mergeSort(head);

        return head;
    }
};