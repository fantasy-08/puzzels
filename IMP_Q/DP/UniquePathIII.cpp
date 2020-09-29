class Solution {
public:
    int dp[20][20][400];
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int go(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>&vis,int C,int cnt){
        int n=grid.size(),m=grid[0].size();
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==-1 || vis[x][y]==true)return 0;
        if(dp[x][y][C]!=-1)return dp[x][y][C];
        if(grid[x][y]==2)return C==cnt?1:0;
        if(grid[x][y]==0)C+=1;
        vis[x][y]=true;
        int ans=0;
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i],Y=y+dy[i];
            ans+=go(X,Y,grid,vis,C,cnt);
        }
        vis[x][y]=false;
        return dp[x][y][C]=ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<bool>>vis(n,vector<bool>(m));
        pair<int,int>st;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    st={i,j};
                }
                else if(grid[i][j]==0)cnt++;
            }
        }
        return go(st.first,st.second,grid,vis,0,cnt);
    }
};