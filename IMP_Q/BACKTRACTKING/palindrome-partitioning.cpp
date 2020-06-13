vector<vector<string>>ans;

void go(int pos,int len,string A,vector<string>a){
    if(pos==A.size()){
        if(a.size())
        ans.push_back(a);
        return ;
    }
    if(pos+len-1>=A.size())return ;
    if(pos>A.size())return;
    string sub=A.substr(pos,len);
    string cp=sub;
    reverse(cp.begin(),cp.end());
    go(pos,len+1,A,a);
    if(cp==sub){
        a.push_back(sub),
        go(pos+len,1,A,a);
    }
}
vector<vector<string> > Solution::partition(string A) {
    ans.clear();
    go(0,1,A,{});
    sort(ans.begin(),ans.end());
    return ans;
}
