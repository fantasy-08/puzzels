class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool dfs(int x,int y,int pos,vector<vector<char>>& board, string word)
    {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='?')return false;
        if(pos==word.size()-1)
        {
            return word[pos]==board[x][y];
        }
        if(word[pos]!=board[x][y])return false;
        char org=board[x][y];
        board[x][y]='?';
        bool ans=false;
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i];
            int Y=y+dy[i];
            ans|=dfs(X,Y,pos+1,board,word);
            if(ans)return true;
        }
        board[x][y]=org;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && dfs(i,j,0,board,word))return true;
            }
        }
        return false;
    }
};