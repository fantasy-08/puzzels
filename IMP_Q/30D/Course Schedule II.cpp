class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        vector<int>adj[n];
        vector<int>in(n,0);
        vector<int>blank;
        for(auto edg:e){
            adj[edg[1]].push_back(edg[0]);
            in[edg[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        if(q.empty())return blank;
        vector<int>topo;
        while(q.size()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto child:adj[node]){
                in[child]--;
                if(in[child]==0)q.push(child);
            }
        }
        if(topo.size()==n)return topo;
        return blank;
    }
};