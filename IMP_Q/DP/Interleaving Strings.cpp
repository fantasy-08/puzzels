int dp[101][101][101];
int go(int i,int j,int k,string A, string B, string C)
{
    if(k==C.size())return true;
    if(i==A.size() && j==B.size())return false;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(i==A.size()){
        if(B[j]!=C[k])return dp[i][j][k]=false;
        dp[i][j][k]=go(i,j+1,k+1,A,B,C);
    }
    if(j==B.size()){
        if(A[i]!=C[k])return dp[i][j][k]=false;
        dp[i][j][k]=go(i+1,j,k+1,A,B,C);
    }
    if(A[i]==B[j] && A[i]==C[k]){
        return dp[i][j][k]=go(i+1,j,k+1,A,B,C) || go(i,j+1,k+1,A,B,C);
    }
    if(A[i]==C[k]){
        return dp[i][j][k]=go(i+1,j,k+1,A,B,C);
    }
    if(B[j]==C[k]){
        return dp[i][j][k]=go(i,j+1,k+1,A,B,C);
    }
    return dp[i][j][k]=false;
}
int Solution::isInterleave(string A, string B, string C) {
    memset(dp,-1,sizeof(dp));
    int n=A.size(),m=B.size(),z=C.size();
    if(n+m!=z)return 0;
    return go(0,0,0,A,B,C)?1:0;
}
