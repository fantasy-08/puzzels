class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        map<pair<int,int>,int>know;
        queue<pair<int,int>>q1;
        queue<vector<int>> q;

        int counter = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1)  {
                    know[{i,j}] = counter++;
                    q1.push({i,j});
                    // cout<<i<<" "<<j<<" -> "<<counter-1<<endl;
                }
            }
        }

        map<pair<int,int>,map<int,int>>score;
        while (q1.size()) {
            vector<vector<bool>>vis(n,  vector<bool>(m,  false));
            // cout<<"Processing - "<<q1.front().first<<" "<<q1.front().second<<endl;
            q.push({q1.front().first,  q1.front().second, 0});
            q1.pop();

            int POINT = know[{q.front()[0], q.front()[1]}];

            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            vis[q.front()[0]][q.front()[1]] = 1;

            while(q.size()) {
                int x = q.front()[0];
                int y = q.front()[1];
                int dis = q.front()[2];
                q.pop();

                for(int i = 0 ; i < 4 ; i++) {
                    int X = x + dx[i], Y = y + dy[i];
                    if (X<0 || Y<0 || X>=n || Y>=m || vis[X][Y] || grid[X][Y] > 0)
                        continue;
                    score[{X, Y}][POINT] = dis + 1;
                    vis[X][Y] = 1;
                    q.push({X, Y, dis+1});
                }
            }
        }

        // test
        // for(auto x:score) {
        //     cout<<x.first.first<<","<<x.first.second<<" -> \n";
        //     for(auto v:x.second)
        //     {
        //         cout<<"\t"<<v.first<<" - "<<v.second<<"\n";
        //     }
        // }

        int dis_ = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)  {
                if (grid[i][j]==0) {
                    int ans = 0;
                    bool pos = true;
                    for(int k=0;k<counter;k++){
                        if(score.find({i, j}) == score.end() 
                            || score[{i,j}].find(k) == score[{i,j}].end()
                        ) {
                            pos = false;
                            break;
                        } else {
                            ans += score[{i, j}][k];
                        }
                    }

                    if(pos) {
                        dis_ = min(dis_, ans);
                    }
                }
            }
        }

        return dis_;
    }
};
