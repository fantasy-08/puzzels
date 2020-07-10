/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head){
        for(Node* root=head;root;root=root->next)
        {
            if(root->child)
            {
                Node* temp=root->next;
                root->next=root->child;
                root->child=nullptr;
                Node* t=root->next;
                t->prev=root;
                while(t->next)
                {
                    t=t->next;
                }
                t->next=temp;
                if(temp)
                temp->prev=t;
            }
        }
        return head;
    }
};