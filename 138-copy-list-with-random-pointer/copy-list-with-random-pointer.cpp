/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
void insertCopyList(Node *head) {
    Node *temp = head;

    while(temp!=nullptr) {
        Node *copy = new Node(temp->val);
        copy->next = temp->next;
        temp->next = copy;
        temp = temp->next->next;
    }
}

void connectRandomPointers(Node *head) {

    Node *temp = head;

    while(temp!=nullptr) {

        if(temp->random) {

        temp->next->random = temp->random->next;

        }
        else {
            temp->next->random = nullptr;
        }
        
        temp = temp->next->next;


    }
}

Node *deepCopyList(Node *head) {

    Node *temp = head;

    Node *dummy = new Node(-1);

    Node *res = dummy;

    while(temp!=nullptr) {
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;

        temp = temp->next;
    }

    return dummy->next;
}
public:
    Node* copyRandomList(Node* head) {
        
        insertCopyList(head);

        connectRandomPointers(head);

        return deepCopyList(head);

    }
};