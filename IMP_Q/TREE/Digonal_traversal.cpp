vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*>q;
    vector<int>arr;
    q.push(A);
    while(q.size())
    {
        TreeNode* root=q.front();
        q.pop();
        while(root)
        {
            arr.push_back(root->val);
            if(root->left) q.push(root->left);
            root=root->right;
        }
    }
    return arr;
}