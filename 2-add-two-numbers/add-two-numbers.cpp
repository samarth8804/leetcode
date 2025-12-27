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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = (temp1->val + temp2->val) / 10;
        int value = (temp1->val + temp2->val) % 10;

        ListNode* l3 = new ListNode(value);
        ListNode* mover = l3;

        temp1 = temp1->next;
        temp2 = temp2->next;

        while (temp1 != nullptr || temp2 != nullptr) {

            if (temp1 != nullptr && temp2 != nullptr) {
                value = (temp1->val + temp2->val + carry) % 10;
                carry = (temp1->val + temp2->val + carry) / 10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1 != nullptr) {
                value = (temp1->val + carry) % 10;
                carry = (temp1->val + carry) / 10;
                temp1 = temp1->next;
            } else {
                value = (temp2->val + carry) % 10;
                carry = (temp2->val + carry) / 10;
                temp2 = temp2->next;
            }

            ListNode* temp = new ListNode(value);
            mover->next = temp;
            mover = mover->next;
        }

        if (carry == 1) {
            ListNode* temp = new ListNode(carry);
            mover->next = temp;
            mover = mover->next;
        }

        return l3;
    }
};