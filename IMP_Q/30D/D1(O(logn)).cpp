class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        long long int l=0,h=n;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            long long int number=(((long long int)mid)*((long long int)mid+1LL))/2LL;
            if(number<=n)
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};