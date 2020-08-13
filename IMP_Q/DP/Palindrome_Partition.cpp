bool Pp[1001][1001];
int  dp[1001][1001];
bool pallindrome(string A){
    string B=A;
    reverse(B.begin(),B.end());
    return A==B;
}
int go(string A,int i,int j)
{
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(Pp[i][j])return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=1;
        if(dp[i][k]==-1)temp+=go(A,i,k);
        else temp+=dp[i][k];
        if(dp[k+1][j]==-1)temp+=go(A,k+1,j);
        else temp+=dp[k+1][j];
        ans=min(ans,temp);
    }
    return dp[i][j]= ans;
}



int Solution::minCut(string A) {
    memset(Pp,false,sizeof(Pp));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<A.size();i++)Pp[i][i]=true;
    for(int i=0;i<A.size()-1;i++){
        if(A[i]==A[i+1])Pp[i][i+1]=true;
    }
    for(int len=3;len<=A.size();len++){
        for(int i=0;i+len-1<A.size();i++){
            int j=i+len-1;
            if(A[i]==A[j])Pp[i][j]=Pp[i+1][j-1];
            else Pp[i][j]=false;
        }
    }
    
    return go(A,0,A.size()-1);
}
