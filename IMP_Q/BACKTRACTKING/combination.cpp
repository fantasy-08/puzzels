vector<vector<int>>ans;
void go(int &k ,int &A,set<int>&a){
    if(a.size()==k){
        vector<int>temp;
        for(auto val:a){
            temp.push_back(val);
        }
        ans.push_back(temp);
        return ;
    }
    for(int i=1;i<=A;i++){
        if(a.find(i)==a.end()){
            a.insert(i);
            go(k,A,a);
            a.erase(a.find(i));
        }
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    ans.clear();
    set<int>useless;
    go(B,A,useless);
    return ans;
}
// -----------PASSED---------------

vector<vector<int>>ans;
void go(int &k ,int &A,set<int>&a,int index){
    if(a.size()==k){
        vector<int>temp;
        for(auto val:a){
            temp.push_back(val);
        }
        ans.push_back(temp);
        return ;
    }
    for(int i=index;i<=A;i++){
        if(a.find(i)==a.end()){
            a.insert(i);
            go(k,A,a,i);
            a.erase(a.find(i));
        }
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    ans.clear();
    set<int>useless;
    go(B,A,useless,1);
    return ans;
}
