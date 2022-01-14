#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int val;
    Tree *left, *right;
};
 
Tree* newNode(int data)
{
    Tree* temp = new Tree();
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

int go(Tree* root, int prev, int diff, bool start){
    if(root==nullptr)
        return 0;
    if(start){
        if(prev-root->val == diff) {
            if(diff<0)
                return 1+go(root->right, root->val, diff, true);
            return 1+go(root->left, root->val, diff, true);
        } else {
            return 0;
        }
    }
    int ans = 0;
    
    if(prev!=-1){
        ans = 1 + go(root, prev, prev-root->val, true);
    }
    ans = max({go(root->right, root->val, diff, false), go(root->left, root->val, diff, false), ans});
    
    return ans;
}

int main()
{
    Tree* root = newNode(6);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->right = newNode(12);
    root->right->right->right = newNode(15);
 
    cout << go(root, -1, 0, false);

    return 0;
}
