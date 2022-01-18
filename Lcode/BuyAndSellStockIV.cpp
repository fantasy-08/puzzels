class Solution {
public:
    int dp[1001][2][101];
    long long go(int pos, bool bought, int k, vector<int>&a){
        if(k==0)return 0;
        if(pos==a.size()){
            if(bought) return INT_MIN;
            return 0;
        }
        
        if(dp[pos][bought][k]!=-1) return dp[pos][bought][k];
        
        long long val = a[pos];
        
        if(bought){
            return dp[pos][bought][k]= max(val+go(pos+1, false, k-1, a), go(pos+1, true, k, a));
        }
        
        return dp[pos][bought][k]= max(-val+go(pos+1, true, k, a), go(pos+1, false, k, a));
    }
    int maxProfit(int k, vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        return go(0,false,k, a);
    }
};
