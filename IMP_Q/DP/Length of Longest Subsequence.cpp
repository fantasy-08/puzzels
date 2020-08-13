int dp[3001][3001][2];
int go(int i,int j,const vector<int> &A,bool inc){
    if(i==A.size())return 0;
    if(j==3001){
        return max(go(i+1,j,A,inc),1+go(i+1,i,A,inc));
    }
    if(dp[i][j][inc]!=-1)return dp[i][j][inc];
    if(inc){
        if(A[i]>A[j]){
            return dp[i][j][inc]=max({1+go(i+1,i,A,inc),go(i+1,j,A,inc),go(i+1,j,A,false),go(i,j,A,false)});
        }
        else{
            return dp[i][j][inc]=max({go(i+1,j,A,inc),go(i+1,j,A,false),go(i,j,A,false)});
        }
    }
    else{
        if(A[i]<A[j]){
            return dp[i][j][inc]=max({1+go(i+1,i,A,inc),go(i+1,j,A,inc)});
        }
        else return dp[i][j][inc]=go(i+1,j,A,inc);
    }
}
int Solution::longestSubsequenceLength(const vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    
    return go(0,3001,A,true);
}
