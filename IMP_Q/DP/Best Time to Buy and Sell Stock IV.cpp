class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())return 0;
        int n=prices.size();
        if(k>(n/2))k=n/2;
        vector<int>prev(n,0),curr(n,0);
        for(int i=1;i<=k;i++)
        {
            int min_term=INT_MIN;
            for(int j=1;j<n;j++)
            {
                min_term=max(min_term,-prices[j-1]+prev[j-1]);
                curr[j]=max(curr[j-1],prices[j]+min_term);
            }
            prev=curr;
            curr.resize(n,0);
        }
        return prev[n-1];
    }
};
