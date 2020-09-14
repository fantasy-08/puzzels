class Solution {
public:
    int dp[20][10000];
    int go(int pos,int S,vector<int>& rods)
    {
        if(pos==rods.size())
        {
            if(S==0)return 0;
            return INT_MIN;
        }
        if(dp[pos][S+5000]!=-1)return dp[pos][S+5000];
        return dp[pos][S+5000]=
        max({
            go(pos+1,S,rods),
            go(pos+1,S+rods[pos],rods)+rods[pos],
            go(pos+1,S-rods[pos],rods)
        });       
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return go(0,0,rods);
    }
};
//Link: https://leetcode.com/problems/tallest-billboard/
