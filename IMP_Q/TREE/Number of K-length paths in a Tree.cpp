#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void merge(map<int,int>& a, map<int,int>& b){
    map<int,int> temp;
    for(auto v:a){
        temp[v.first] += v.second;
    }
    for(auto v:b){
        temp[v.first] += v.second;
    }
    a = temp;
}

map<int,int> go(Node* root,int k, int& ans, int depth) {
    map<int,int> left, right;
    if(root==nullptr)
        return left;
    left = go(root->left, k, ans, depth+1);
    right = go(root->right, k, ans, depth+1);
    int temp_ans = left[depth + k] + right[depth+k];
    for(auto v:left) {
        if(v.first != depth+k){
            int len = k - v.first;
            int req = k - len;
            temp_ans += (v.second * right[req]);
        }
    }
    
    ans += temp_ans;
    
    merge(left, right);
    left[depth]+=1;
    
    return left;
}

int main()
{
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    
    int ans = 0;
    go(root, 2, ans, 0);
    
    cout<<ans<<endl;
    return 0;
}
