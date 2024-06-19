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
    void print(Node* node){
        Node* temp = node;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            Node* next = temp->next;
            temp->next = newNode;
            newNode->next = next;
            temp = next;
        }
        temp = head;

        while(temp != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node * newNode = new Node(-1);
        // print(newNode);
        temp = head;
        Node* res = newNode;
        while(temp != NULL){
            res ->next = temp->next;
            res= res->next;

            temp->next = temp->next->next; 
            temp = temp->next;
        }
        print(newNode);
        return newNode->next;
    }
};