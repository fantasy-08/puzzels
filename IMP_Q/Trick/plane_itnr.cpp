class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>>adj;
        stack<string>s;
        for(auto tkt:tickets){
            adj[tkt[0]].insert(tkt[1]);
        }
        vector<string>ans;
        s.push("JFK");
        while(!s.empty()){
            string node=s.top();
            if(adj[node].size()==0){
                ans.push_back(node);
                s.pop();
            }
            else{
                string child=*adj[node].begin();
                adj[node].erase(adj[node].begin());
                s.push(child);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};