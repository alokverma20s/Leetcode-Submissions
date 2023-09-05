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
        Node* curr = head;
        Node* head2 = NULL, *tail = NULL;
        while(curr != NULL){
            Node* temp = new Node(curr->val);
            if(head2 == NULL){
                head2 = temp;
                tail = head2;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            curr = curr->next;
        }
        curr = head;
        tail = head2;
        while(curr != NULL){
            if(curr->random == NULL){
                curr = curr->next;
                tail = tail->next;
            }
            else{
                // cout<<curr->random->val<<" ";
                Node * temp = head2;
                Node* temp2 = head;
                while(curr->random != temp2){
                    temp = temp->next;
                    temp2 = temp2->next;
                }
                tail->random = temp;
                tail= tail->next;
                curr =  curr->next;
            }
        }
        return head2;
    }
};