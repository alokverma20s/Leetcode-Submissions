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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;

        for(int i=0; i< n;i++) fast = fast ->next;

        if(fast == NULL) return head->next;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast ->next;
        }
        ListNode* delNode = slow->next;
        slow ->next = delNode->next;
        delete delNode;
        return head;
    }
};