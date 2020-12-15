int F(int x,vector<int>&pre,char c)
{
    if(x==0)return 0;
    
    int ind=upper_bound(pre.begin(),pre.end(),x)-pre.begin();
    ind--;
    
    int ans=((ind)*(ind+1))/2,ascii=c-'a';
    
    if(pre[ind]==x)return ans;
    
    int start=pre[ind]+1+(ind+1)*(ascii);
    int end=min(ind,start+ind);
    
    if(start>end)return ans;
    
    ans+=end-start+1;
    return ans;
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int>pre;
    pre.push_back(0);
    int prev=0,dif=26;
    for(int i=1;i<=9000;i++){
        pre.push_back(prev+dif);
        prev=prev+dif,dif+=26;
    }
    
    char S[5]={'a','e','i','o','u'};
    
    vector<int>Ans;
    for(vector<int>Q:A)
    {
        int l=Q[0],r=Q[1];
        int ans=0;
        for(int i=0;i<5;i++)
            ans+=F(r,pre,S[i])-F(l-1,pre,S[i]);
    
        Ans.push_back(ans);
    }
    
    return Ans;
}
/*
abc...zaabb.....zz
1                                       26
27                                      27+26*2-1
27+26*3                                 27+26*4-1
*/ 
