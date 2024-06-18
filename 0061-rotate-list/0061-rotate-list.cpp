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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int l = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            l++;
            temp = temp->next;
        }
        temp->next= head;
        k = k % l;
        int r = l -k;
        ListNode* last = head;
        for(int i=0; i< r-1; i++){
            last = last->next;
        }
        head = last->next;
        last->next = NULL;
        return head;

    }
};