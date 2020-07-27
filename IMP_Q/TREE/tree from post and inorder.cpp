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
// inorder LDR
// post    LRD
class Solution {
public:
    int Find(vector<int>&in,int num){
        for(int i=0;i<in.size();i++){
            if(in[i]==num)return i;
        }
        return 0;
    }
    TreeNode* help(vector<int>in,vector<int>post)
    {
        if(in.empty()||post.empty())return nullptr;
        if(post.size()==1)return new TreeNode(post[0]);

        TreeNode* root=new TreeNode(post[post.size()-1]);
        int ind=Find(in,post[post.size()-1]);

        vector<int>leftin,rightin,leftpost,rightpost;
        
        for(int i=0;i<ind;i++)leftin.push_back(in[i]);
        for(int i=ind+1;i<in.size();i++)rightin.push_back(in[i]);
        for(int i=0;i<leftin.size();i++)leftpost.push_back(post[i]);
        for(int i=leftin.size();i<post.size()-1;i++)rightpost.push_back(post[i]);

        root->left=help(leftin,leftpost);
        root->right=help(rightin,rightpost);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder,postorder);
    }
};
