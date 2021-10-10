// may God and Me, Fly!
// not tested yet
// use with caution 

class Graph {
    private:
        vector < vector < int >> adj, edg;
        int N;
        vector < int > in , low, indeg, vis;
        map < pair < int, int > , int > Weight;

    Graph(int N) {
        this -> N = n;
        this -> adj.resize(this -> N, vector < int > ()); this -> in .resize(this -> N, 0);
        this -> low.resize(this -> N, INT_MAX);
        this -> indeg.resize(this -> N, 0);
    }

    public:
        void insert(int u, int v) {
            this -> adj[u].insert(v);
            this -> indeg[v]++;
            this -> edg.push_back({u,v,0});
        }

    public:
        void insertWeight(int u, int v, int w) {
            this -> adj[u].insert(v);
            this -> indeg[v]++;
            Weight[{
                u,
                v
            }] = w;
            this -> edg.push_back({u,v,w});
        }

    public:
        vector < int > topoSort() {
            vector < int > ans, indeg(this->indeg.begin(),this->indeg.end());

            queue < int > q;
            for (int i = 0; i < this -> N; i++)
                if (indeg[i] == 0)
                    q.push(i);

            while (q.size()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto child: this -> adj[node]) {
                    indeg[child]--;
                    if (indeg[child] == 0) {
                        q.push(child);
                    }
                }
            }

            return ans.size() == N ? ans : {};
        }
    private:
        void findBridgeUtil(int node,int par,int& time_,vector<pair<int,int>>&ans){
            this -> in[time_] = this -> low[time_] = time_++;
            for(auto child:this -> adj[node]){
                if(child==par)
                    continue;
                if(!vis[child]){
                    low[node]=min(low[child], low[node]);
                }else{
                    findBridgeUtil(child,node,time_,ans);
                    low[node]=min(low[child], low[node]);
                    if(in[node] < low[child]){
                        ans.push_back({node,child});
                    }
                }
            }
        }

    public:
        vector<pair<int,int>> findBridge(){
            vector<pair<int,int>> ans;
            vis.clear();
            vis.resize(this->N, 0);
            for(int i=0;i<this->N;i++){
                if(this->in[i]==0){
                    int time_=0;
                    findBridgeUtil(i,-1,time_,ans);
                }
            }
            return ans;
        }
    
    public:
        vector<int> bellmanShort(int u){
            int times = this->N;
            vector<int>dis(this->N,INT_MAX);
            dis[u]=0;
            while(times--){
                for(auto edge : this->edg){
                    int u = edge[0], v= edge[1],w=edge[2];
                    if(dis[u] + w < dis[v]){
                        dis[v]=dis[u]+w;
                    }
                }
            }
            return dis;
        }
}
