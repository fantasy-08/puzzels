#include<bits/stdc++.h>
using namespace std;
int dp[100001][2];

int go(int i,bool even,vector<int>&A)
{
    if(i==A.size()) return 0;
    if(dp[i][even]!=-1)return dp[i][even];
    if(even)
    {
        return dp[i][even]=max(-A[i]+go(i+1,false,A),go(i+1,true,A));
    }
    else
    {
        return dp[i][even]=max(A[i]+go(i+1,true,A),go(i+1,false,A));
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    vector<int>query={6 ,7, 5, 1, 9, 2, 10};
    cout<<go(0,false,query)<<endl;
}
