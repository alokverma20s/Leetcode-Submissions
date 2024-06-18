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
        k = k % l;

        if(k == 0)
            return head;

        int r = l -k;
        ListNode* last = temp;
        temp = head;
        for(int i=0; i< r-1; i++){
            temp = temp->next;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        last->next = head;
        return next;

    }
};