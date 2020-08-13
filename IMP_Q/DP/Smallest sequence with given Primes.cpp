vector<int> Solution::solve(int A, int B, int C, int k) {
    vector<int>ans;
    int no[]={A,B,C};
    unordered_set<int>vis,uni;
    uni.insert(A);uni.insert(B);uni.insert(C);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<3;i++)q.push(no[i]);
    while(ans.size()!=k)
    {
        int u = q.top();
        uni.insert(u);
        if(vis.find(u)==vis.end())
            ans.push_back(u),vis.insert(u);
        q.pop();
        for(int i=0;i<3;i++)
        {
            if(uni.find(u*no[i])==uni.end())
            {
                 q.push(u*no[i]);
            }
        }
    }
    return ans;
}
