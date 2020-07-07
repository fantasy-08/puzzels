vector<vector<int> > Solution::subsets(vector<int> &A) {
    set<vector<int>>ans;
    vector<vector<int>>q;
    q.push_back({});
    for(int i=0;i<A.size();i++){
        int n=q.size();
        for(int j=0;j<n;j++){
            auto temp=q[j];
            temp.push_back(A[i]);
            q.push_back(temp);
        }
    }
    for(auto Q:q){
        sort(Q.begin(),Q.end());
        ans.insert(Q);
    }
    vector<vector<int>>Ans;
    for(auto v:ans){
        Ans.push_back(v);
    }
    return Ans;
}
