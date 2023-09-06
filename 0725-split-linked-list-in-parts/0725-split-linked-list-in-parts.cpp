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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int size =0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp = temp -> next;
            size++;
        }
        if(size==0){
            int runtime =0;
            while(runtime<k){
                result.push_back(NULL);
                runtime++;
            }
        }
        else{
        int n = size/k;
        int rem = size%k;
        int count =0;
        ListNode* curr =head;
        ListNode* prev = NULL;
        if(n!=0){
        while(count<rem){
            result.push_back(curr);
            int runtime =0;
            while(runtime<n+1){
                prev =curr;
                curr =curr -> next;
                runtime++;
            }
            count++;
            prev ->next =NULL;
        }
        count =0;
        while(count<k-rem){
            result.push_back(curr);
            int runtime =0;
            while(runtime<n){
                prev =curr;
                curr = curr ->next;
                runtime++;
            }
            count++;
            prev->next  =NULL;
        }
        }
        else{
            while(count<rem){
            result.push_back(curr);
            int runtime =0;
            while(runtime<n+1){
                prev =curr;
                curr =curr -> next;
                runtime++;
            }
            prev->next =NULL;
            count++;
        }
        count =0;
            while(count<k-rem){
            result.push_back(curr);
            int runtime =0;
            while(runtime<n){
                prev =curr;
                curr = curr ->next;
                runtime++;
            }
            count++;
            prev->next  =NULL;
        }
        }
        }
        return result;
    }
};