#include <bits/stdc++.h>

class Graph {
    private:
        vector < vector < int >> adj, edg;
    int N;
    vector < int > in , low, indeg, vis;
    map < pair < int, int > , int > Weight;

    Graph(int N) {
        this -> N = n;
        adj.resize(this -> N, vector < int > ()); in .resize(this -> N, 0);
        low.resize(this -> N, INT_MAX);
        indeg.resize(this -> N, 0);
    }

    public:
        void insert(int u, int v) {
            adj[u].insert(v);
            indeg[v]++;
            edg.push_back({
                u,
                v,
                0
            });
        }

    public:
        void insertWeight(int u, int v, int w) {
            adj[u].insert(v);
            indeg[v]++;
            Weight[{
                u,
                v
            }] = w;
            edg.push_back({
                u,
                v,
                w
            });
        }

    public:
        vector < int > topoSort() {
            vector < int > ans;

            queue < int > q;
            for (int i = 0; i < this -> N; i++)
                if (indeg[i] == 0)
                    q.push(i);

            while (q.size()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto child: adj[node]) {
                    indeg[child]--;
                    if (indeg[child] == 0) {
                        q.push(child);
                    }
                }
            }

            return ans.size() == N ? ans : {};
        }
    private:
        void findBridgeUtil(int node, int par, int & time_, vector < pair < int, int >> & ans) {
            in [time_] = low[time_] = time_++;
            for (auto child: adj[node]) {
                if (child == par)
                    continue;
                if (!vis[child]) {

                } else {
                    findBridgeUtil(child, node, time_, ans);
                    low[node] = min(low[child], low[node]);
                    if ( in [node] < low[child]) {
                        ans.push_back({
                            node,
                            child
                        });
                    }
                }
            }
        }

    public:
        vector < pair < int, int >> findBridge() {
            vector < pair < int, int >> ans;
            vis.clear();
            vis.resize(this -> N, 0);
            for (int i = 0; i < this -> N; i++) {
                if (this -> in [i] == 0) {
                    int time_ = 0;
                    findBridgeUtil(i, -1, time_, ans);
                }
            }
            return ans;
        }

    public:
        vector < int > bellmanShort(int u) {
            int times = this -> N;
            vector < int > dis(this -> N, INT_MAX);
            dis[u] = 0;
            while (times--) {
                for (auto edge: this -> edg) {
                    int u = edge[0], v = edge[1], w = edge[2];
                    if (dis[u] + w < dis[v]) {
                        dis[v] = dis[u] + w;
                    }
                }
            }
            return dis;
        }
}
