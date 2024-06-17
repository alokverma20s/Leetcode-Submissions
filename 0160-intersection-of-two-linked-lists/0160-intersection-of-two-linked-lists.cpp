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
        ListNode* d1 = headA;
        unordered_set<ListNode*> st;

        while(d1 != NULL){
            st.insert(d1);
            d1 = d1->next;
        }

        ListNode* d2 = headB;
        while(d2 != NULL){
            if(st.find(d2) != st.end())
                return d2;
            d2 = d2->next;
        }

        return NULL;
    }
};