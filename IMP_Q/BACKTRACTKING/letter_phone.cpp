map<int,string>f;
vector<string>ans;

void go(int pos,string A,string a){
    if(pos==A.size()){
        ans.push_back(a);
        return ;
    }
    if(A[pos]=='0'){
        a+='0';
        go(pos+1,A,a);
        return ;
    }
    else if(A[pos]=='1'){
        a+=A[pos];
        go(pos+1,A,a);
    }
    int no=A[pos]-'0';
    for(auto c:f[no]){
        go(pos+1,A,a+c);
    }
}
vector<string> Solution::letterCombinations(string A) {
    f[2]="abc",f[3]="def",f[4]="ghi",f[5]="jkl",f[6]="mno",f[7]="pqrs",f[8]="tuv",f[9]="wxyz";
    ans.clear();
    go(0,A,"");
    return ans;
}
