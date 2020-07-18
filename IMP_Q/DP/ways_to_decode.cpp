int dp[100000];
const int m=1e9+7;
int go(int i,string A)
{
    if(i>=A.size())return 1;
    if(dp[i]!=-1)return dp[i]%m;
    if(A[i]=='0')return dp[i]=0;
    if(A[i]=='1')
        if(i==A.size()-1)return dp[i]=1;
        else return dp[i]= (go(i+1,A)%m+go(i+2,A)%m)%m;
    if(A[i]=='2')
    {
        if(i==A.size()-1)return dp[i]= 1;
        if(A[i+1]<='6' && A[i+1]>='0')return dp[i]= (go(i+1,A)%m+go(i+2,A)%m)%m;
        return dp[i]= go(i+1,A)%m;
    }
    return dp[i]=go(i+1,A)%m;
}
int Solution::numDecodings(string A) {
    memset(dp,-1,sizeof(dp));
    return go(0,A)%m;
}
