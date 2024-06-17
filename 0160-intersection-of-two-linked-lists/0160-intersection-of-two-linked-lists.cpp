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
        ListNode* d1 = headA, *d2 = headB;
        int cnt1 = 0, cnt2 = 0;

        while(d1 != NULL || d2 != NULL){
            if(d1 != NULL){
                cnt1++;
                d1= d1->next;
            }
            if(d2 != NULL){
                cnt2++;
                d2 = d2->next;
            }
        }
        int diff = abs(cnt1-cnt2);
        cnt1 < cnt2 ? d1= headB : d1 = headA;
        cnt1 < cnt2 ? d2= headA : d2 = headB;

        while(diff--) d1 = d1->next;

        while(d1 != NULL){
            if(d1 == d2)
                return d1;
            d1 = d1->next;
            d2 = d2->next;
        }
        return NULL;
    }
};