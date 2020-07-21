int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>pre(n);
    pre[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)pre[i]=max(A[i],pre[i+1]);
    set<int>s;
    s.insert(A[0]);
    int ans=-1;
    for(int i=1;i<n-1;i++){
        int mid=A[i];
        int nxt=pre[i+1];
        if(nxt<=mid)continue;
        s.insert(A[i]);
        auto it=s.find(A[i]);
        if(it==s.begin())continue;
        it=prev(it);
        ans=max(*it+mid+nxt,ans);
    }
    return ans;
}





