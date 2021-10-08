class DSU {
    private:
        vector < int > parent, size, rank;
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(0);
            size.push_back(0);
            rank.push_back(0);
        }
    }

    public:
        int findPar(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = findPar(parent[u]);
        }
    public:
        void union(int u, int v) {
            int p1 = findPar(u);
            int p2 = findPar(v);
            if (p1 == p2)
                return;
            if (size[p1] > size[p2]) {
                parent[p2] = p1;
                size[p2] += size[p1];
            } else {
                parent[p1] = p2;
                size[p1] += size[p2];
            }
        }
    public:
        void unionRank(int u, int v) {
            int p1 = findPar(u);
            int p2 = findPar(v);
            if (p1 == p2)
                return;
            if (rank[p1] == rank[p2]) {
                parent[p1] = p2;
                rank[p2]++;
            } else if (rank[p1] > rank[p2]) {
                parent[p2] = p1;

            } else {
                parent[p1] = p2;
            }
        }
}
