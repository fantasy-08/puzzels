class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans(n+1,0);
        ans[0]=1;
        for(int i=0;i<n;i++){
            vector<int>temp(n+1,0);
            for(int j=0;j<i+2;j++){
                temp[j]=ans[j]+((j!=0)?ans[j-1]:0);                
            }
            ans=temp;
        }
        return ans;
    }
};