/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *dummy1 = headA;
        ListNode *dummy2 = headB;
        int len1 = 0;
        int len2 = 0;

        while(dummy1 != nullptr || dummy2 != nullptr) {
            if(dummy1 != nullptr) {
                len1++;
                dummy1 = dummy1->next;
            }
            if(dummy2 != nullptr) {
                len2++;
                dummy2 = dummy2->next;
            }
        }

        dummy1 = headA;
        dummy2 = headB;

        if(len1 <= len2) {
            for(int i=0;i<(len2-len1);i++) {
                dummy2 = dummy2->next;
            }
        }
        else {
            for(int i=0;i<(len1-len2);i++) {
                dummy1 = dummy1->next;
            }
        }

        while(dummy1 != dummy2) {
            dummy1 = dummy1->next;
            dummy2 = dummy2->next;
        }

        return dummy1;
    }
};