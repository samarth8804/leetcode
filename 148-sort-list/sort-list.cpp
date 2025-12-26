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
    ListNode* sortList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        vector<int> arr;

        ListNode *temp = head;

        while(temp!= nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(),arr.end());

        head = new ListNode(arr[0]);
        temp = head;

        for(int i=1;i<arr.size();i++) {
            ListNode *tmp = new ListNode(arr[i]);
            temp->next = tmp;
            temp = temp->next;
        }

        return head;
    }
};