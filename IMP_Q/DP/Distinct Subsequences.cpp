int dp[1001][1001];
int go(int i,int j,string A,string B){
    if(j==B.size())return 1 ;
    if(i==A.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(A[i]==B[j]){
        return dp[i][j]=go(i+1,j+1,A,B)+go(i+1,j,A,B);
    }
    return dp[i][j]=go(i+1,j,A,B);
}
int Solution::numDistinct(string A, string B) {
    memset(dp,-1,sizeof(dp));
    return go(0,0,A,B);
}
