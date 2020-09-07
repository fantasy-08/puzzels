//https://leetcode.com/contest/biweekly-contest-34/problems/count-all-possible-routes/
class Solution {
public:
    int dp[101][201];
    int n;
    const int m=1e9+7;
    int go(int pos,int f,vector<int>& arr, int fi)
    {
        int val=0;
        if(pos==fi)val=1;
        if(f<=0)return val;
        if(dp[pos][f]!=-1)return dp[pos][f];
        int ans=0;
        for(int i=pos+1;i<n;i++){
            if(abs(arr[pos]-arr[i])>f)break;
            ans=(ans%m+(go(i,f-abs(arr[pos]-arr[i]),arr,fi)%m))%m;
        }
        for(int i=pos-1;i>=0;i--){
            if((arr[pos]-arr[i])>f)break;
            ans=(ans%m+(go(i,f-abs(arr[pos]-arr[i]),arr,fi)%m))%m;
        }
        return dp[pos][f]=(ans%m+val%m)%m;
    }
    int countRoutes(vector<int>& arr, int start, int finish, int fuel) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        int st=arr[start],fi=arr[finish];
        sort(arr.begin(),arr.end());
        int pos1,pos2;
        for(int i=0;i<n;i++){
            if(arr[i]==st)pos1=i;
            if(arr[i]==fi)pos2=i;
        }
        return go(pos1,fuel,arr,pos2);
    }
};
