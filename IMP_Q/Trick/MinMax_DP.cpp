class Solution {
public:
    int dp[1000][1000];
    int go(int s,int e){
        if(s>=e)return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int res=INT_MAX;
        for(int i=s;i<=e;i++){
            int temp=i+max(go(i+1,e),go(s,i-1));
            res=min(res,temp);
        }
        return dp[s][e]=res;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return go(1,n);
    }
};
@https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/
