int dp[100001];
int go(int i,vector<vector<int> > &A){
    if(i>=A[0].size())return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=A[0][i]+go(i+2,A);
    ans=max(ans,A[1][i]+go(i+2,A));
    ans=max(ans,go(i+1,A));
    return dp[i]=ans;
}
int Solution::adjacent(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    return go(0,A);
}
