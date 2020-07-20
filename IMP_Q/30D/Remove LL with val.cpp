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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*prev=NULL,*a=head;
        while(a){
            if(a->val==val){
                if(prev){
                    prev->next=a->next;
                    a=a->next;
                }
                else head=head->next,a=a->next;
            }
            else{
                prev=a;
                a=a->next;
            }
        }
        return head;
    }
};