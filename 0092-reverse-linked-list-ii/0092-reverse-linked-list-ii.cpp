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
    ListNode* reverse(ListNode* head){
        ListNode* forward , *prev = NULL, *curr = head;
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans = NULL, *tail =NULL, *temp;
        int cnt =1;
        if(left == right)
            return head;
        while(cnt<left){
            if(ans==NULL){
                ans = head;
                tail = ans;
                head = head->next;
                ans->next = NULL;
            }
            else{
                tail->next = head;
                tail = head;
                head= head->next;
                tail->next = NULL;
            }
            cnt++;
        }
        temp = head;
        while(cnt<right){
            head = head->next;
            cnt++;
        }
        ListNode* tail2= head;
        head = head->next;
        tail2->next = NULL;
        temp = reverse(temp);
        if(tail == NULL){
            ans = temp;
            tail = temp;
        }
        else
            tail ->next = temp;
        while(tail->next!=NULL){
            tail= tail->next;
        }
        tail ->next = head;
        return ans;

    }
};