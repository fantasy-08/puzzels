class Solution {
public:
    vector<int>pos(int x,vector<int>& nums)
    {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(x&(1<<i))ans.push_back(nums[i]);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i=0;i<=pow(2,(int)nums.size())-1;i++){
            ans.push_back(pos(i,nums));
        }
        return ans;
    }
};