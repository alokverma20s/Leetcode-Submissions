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
    ListNode* reverseLinkedList(ListNode *head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front; 
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* node, int k){
        k--;
        while(node != nullptr && k--){
            node = node->next;
        }
        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* kth = getKthNode(temp, k);

            if(kth == nullptr){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* next = kth->next;
            kth->next = nullptr;

            reverseLinkedList(temp);

            if(temp==head) head = kth;
            else prev->next = kth;

            prev = temp;
            temp = next;
        }
        return head;
    }
};