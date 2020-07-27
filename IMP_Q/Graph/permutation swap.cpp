vector<int>par;
int find(int node){
    if(par[node]<0)return node;
    return par[node]=find(par[node]);
}
void Union(int a,int b){
    int P1=find(a);
    int P2=find(b);
    if(P1!=P2){
        par[P1]=P2;
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    par.clear();
    int n=A.size();
    par.resize(n,-1);
    for(auto edge:C){
        Union(edge[0]-1,edge[1]-1);
    }
    map<int,int>index;
    for(int i=0;i<B.size();i++)index[B[i]]=i;
    for(int i=0;i<n;i++){
        if(A[i]==B[i])continue;
        int P=find(index[A[i]]);
        int T=find(i);
        if(P!=T)return false;
    }
    return true;
}
