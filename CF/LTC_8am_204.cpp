//A
class Solution {
public:
    int go(vector<int>& arr,int pos,deque<int> con,int m,int k,bool st){
        if(pos>arr.size())return 0;
        if(pos==0){
            deque<int>a;
            int temp=0;
            for(int i=0;i<m;i++){
                a.push_back(arr[i]);
            }
            temp=go(arr,m,a,m,k,true);
            for(int i=m;i<arr.size();i++){
                a.pop_front();
                a.push_back(arr[i]);
                temp=max(temp,go(arr,i+1,a,m,k,true));
            }
            return temp;
        }
        if((arr.size()-pos)<m)return 0;
        deque<int>temp;
        for(int i=0;i<m;i++){
            temp.push_back(arr[i+pos]);
        }
        if(temp==con){
            if(st)return 2+go(arr,pos+m,con,m,k,false);
            return 1+go(arr,pos+m,con,m,k,false);
        }
        return 0;        
    }
    bool containsPattern(vector<int>& arr, int m, int k) {
        deque<int>us;
        int ans=go(arr,0,us,m,k,false);
        return ans>=k;
    }
};

//B
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        pair<int,int>val={0,-1};
        int tot=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)val={i+1,-1},tot=0;
            if(nums[i]<0 && val.second==-1)val.second=i;
            if(nums[i]<0)tot++;
            if(tot%2==0)ans=max(ans,i-val.first+1);
            else ans=max(ans,i-val.second);
        }
        return ans;
    }

//C
class Solution {
public:
    vector<vector<bool>>vis;
    int n,m;
    void dfs(int x,int y,vector<vector<int>>&adj){
        if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || adj[x][y]==0)return ;
        vis[x][y]=true;
        dfs(x+1,y,adj);
        dfs(x-1,y,adj);
        dfs(x,y+1,adj);
        dfs(x,y-1,adj);
    }
    int minDays(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis.resize(n,vector<bool>(m,false));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        if(island>1 || island==0)return 0;
        //either 1 or 2;
        //..checking for 1..
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    vis.clear();
                    island=0;
                    vis.resize(n,vector<bool>(m,false));
                    int island=0;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(!vis[i][j] && grid[i][j]){
                                island++;
                                dfs(i,j,grid);
                            }
                        }
                    }
                    if(island>1)return 1;
                    grid[i][j]=1;
                }
            }
        }
        //one not possible answer is 2
        return 2;
    }
};
//D
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/discuss/819450/python-O(n-log-n)-solution
