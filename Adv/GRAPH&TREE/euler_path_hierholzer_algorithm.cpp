class Solution {
public:
    void go(map<int,vector<int>>& adj, int node, vector<int>&path, map<int,int>&out){
        while(out[node]!=0){
            int next = adj[node][out[node]-1];
            out[node]--;
            go(adj, next,path,out);
        }
        path.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>>adj;
        map<int,int>in, out;
        
        for(auto p:pairs){
            adj[p[0]].push_back(p[1]);
            in[p[1]]++, out[p[0]]++;
        }
        
        int start = pairs[0][0];
        for(auto v:out){
            if(out[v.first]-in[v.first] == 1){
                start = v.first;
            }
        }
        
        vector<int>path;
        go(adj, start, path, out);
        reverse(path.begin(),path.end());
        
        int i = 0, j = 0;
        while(i<path.size()-1 && j<pairs.size()){
            pairs[j][0] = path[i];
            pairs[j++][1] = path[i+1];
            i++;
        }

        return pairs;
    }
};
