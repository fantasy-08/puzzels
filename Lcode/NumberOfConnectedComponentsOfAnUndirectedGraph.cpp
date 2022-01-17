#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int>parent, size;
    
    public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i, size[i]=0;
        }
    }
    
    public:
    int Root(int node) {
        while(node!=parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    
    public:
    void Union(int a, int b) {
        int pa = Root(a);
        int pb = Root(b);
        
        if(pa == pb)
            return ;
        
        if(size[pa] > size[pb]){
            size[pa]+=size[pb];
            parent[pb] = pa;
        } else {
            size[pb]+=size[pa];
            parent[pa] = pb;
        }
    }
};

int solution (vector<vector<int>>edges, int n) {
    DSU* dsu = new DSU(n);
    for(auto edge : edges) {
        dsu->Union(edge[0], edge[1]);
    }
    
    set<int>parents;
    for(int i=0;i<n;i++){
        parents.insert(dsu->Root(i));
    }
    
    return parents.size();
}

int main()
{
    cout<<solution({{0,1},{1,2},{3, 4}}, 5);

    return 0;
}
