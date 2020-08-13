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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        bool flag=false;
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            vector<int>Temp;
            while(n--){
                TreeNode* R=q.front();
                q.pop();
                Temp.push_back(R->val);
                if(R->left)q.push(R->left);
                if(R->right)q.push(R->right);
            }
            if(flag)reverse(Temp.begin(),Temp.end());
            flag=!flag;
            ans.push_back(Temp);
        }
        return ans;
    }
};
