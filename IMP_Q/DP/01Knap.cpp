int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    int w=C;
    int dp[n+1][w+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(B[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],A[i-1]+dp[i-1][j-B[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
