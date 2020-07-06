class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        vector<int>ans;
        int carry=1;
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]+carry;
            if(temp>9)carry=1;
            else carry=0;
            ans.push_back(temp%10);
        }
        if(carry)ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};