set<string>ans;
void go(int o,int c,int n,string s){
    if(o==c && o==n){
        ans.insert(s);
        return ;
    }
    if(o>n || c>n)return ;
    if(c>o)return ;
    if(o>c){
        string y="";
        for(int i=c+1;i<=o;i++){
            y+=')';
            go(o,i,n,s+y);
        }
        go(o+1,c,n,s+'(');
        return ;
    }
    if(o==c)go(o+1,c,n,s+'(');
}
vector<string> Solution::generateParenthesis(int A) {
    ans.clear();
    go(0,0,A,"");
    vector<string>aL;
    for(auto v:ans)aL.push_back(v);
    return aL;
}
