class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=nums[i]%(n+1);
            nums[ind-1]+=(n+1);
        };
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>(2*n+2))ans.push_back(i+1);
        }
        return ans;
    }
};
