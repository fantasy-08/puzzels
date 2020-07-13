#include<bits/stdc++.h>
vector<bool>vis,s;
vector<vector<int>>adj;
bool dfs(int node)
{
    if(vis[node]==false)
    {
        vis[node]=true;
        s[node]=true;
        for(auto child:adj[node]){
            if(!vis[child] && dfs(child))return true;
            else if(s[child])return true;
        }
        s[node]=false;
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    if(B.size()<=2)return false;
    vis.clear();
    adj.clear();
    s.clear();
    adj.resize(A+1,vector<int>());
    for(auto edg:B)
    {
        int u=edg[0];
        int v=edg[1];
        adj[u].push_back(v);
    }
    vis.resize(A+1,false);
    s.resize(A+1,false);
    for(int i=1;i<=A;i++){
        if(dfs(i))return true;
    }
    return false;
}
