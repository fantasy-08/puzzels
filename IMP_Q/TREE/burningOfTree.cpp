class Solution {
  public:
    vector<vector<int>>ans;
    bool go(Node* root,  int target, queue<Node*>& q) {
        if(root==nullptr)
            return false;
        if (root->data == target)
        {
            ans.push_back({root->data});
            if (root->left!=nullptr)
                q.push(root->left);
            if (root->right!=nullptr)
                q.push(root->right);
            return true;
        }
        
        bool right = go(root->right, target, q);
        bool left = go(root->left, target, q);
        if (left || right) {
            vector<int>tempA;
            tempA.push_back(root->data);
            int n = q.size();
            while(n--) {
                Node* temp = q.front();
                q.pop();
                tempA.push_back(temp->data);
                if (temp->left!=nullptr)
                    q.push(temp->left);
                if (temp->right!=nullptr)
                    q.push(temp->right);
            }
            ans.push_back(tempA);
            if (left && root->right!=nullptr) {
                q.push(root->right);
            }
            if (right && root->left!=nullptr) {
                q.push(root->left);
            }
            return true;
        }
        return false;
    }
    int minTime(Node* root, int target) 
    {
        ans.clear();
        queue<Node*> q;

        go(root, target, q);
        
        while (q.size()) {
            vector<int>tempA;
            int n = q.size();
            while(n--) {
                Node* temp = q.front();
                q.pop();
                tempA.push_back(temp->data);
                if (temp->left!=nullptr)
                    q.push(temp->left);
                if (temp->right!=nullptr)
                    q.push(temp->right);
            }
            ans.push_back(tempA);
        }
        
        // for(auto a:ans) {
        //     for(int v:a){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans.size() == 0 ? 0 : ans.size() - 1;
    }
};
