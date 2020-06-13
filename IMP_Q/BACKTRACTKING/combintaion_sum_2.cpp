set<vector<int>>ans;
void go(int s,int t,int i,vector<int>&A,vector<int>loc){
    if(s==t){
        ans.insert(loc);
        return ;
    }
    if(i==A.size())return ;
    if(s>t)return ;
    for(int j=i;j<A.size();j++){
        if(s+A[j]<=t){
            loc.push_back(A[j]);
            go(s+A[j],t,j+1,A,loc);
            loc.erase(prev(loc.end()));
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    ans.clear();
    vector<int>u;
    go(0,B,0,A,u);
    vector<vector<int>>Ao;
    for(auto v:ans)Ao.push_back(v);
    return  Ao;
}
