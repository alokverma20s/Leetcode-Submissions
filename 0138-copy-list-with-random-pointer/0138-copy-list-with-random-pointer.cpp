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
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node* newHead = new Node(head->val);
        Node* t = newHead;

        unordered_map<Node*, Node*> mp;
        mp[head]= t; 
        Node* temp = head->next;
        while(temp != NULL){
            t->next = new Node(temp->val);
            t = t->next;
            mp[temp] = t;
            temp = temp->next;
        }
        t = newHead;
        temp = head;
        while(t != NULL){
            if(temp->random != NULL)
            t->random = mp[temp->random];
            t = t->next;
            temp = temp->next;
        }
        return newHead;
    }
};