/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode*>q;
        q.push_back(root);
        int ans=0;
        while(q.size())
        {
            while(q.size() && q.front()==nullptr)q.pop_front();
            while(q.size() && q.back ()==nullptr)q.pop_back() ;
            int n=q.size();
            ans=max(ans,n);
            for(int i=0;i<n;i++)
            {
                TreeNode* Temp=q.front();
                q.pop_front();
                if(Temp==nullptr)
                {
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                }
                else
                {
                    q.push_back(Temp->left );
                    q.push_back(Temp->right);
                }
            }
        }
        return ans;
    }
};
