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
    ListNode* middleNode(ListNode* head) {
        
        int length = 0;

        ListNode *temp = head;

        while(temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int k = (length/2)+1;


        temp = head;
        for(int i=1;i<k;i++) {
            temp = temp->next;
        }

        return temp;
    }
};