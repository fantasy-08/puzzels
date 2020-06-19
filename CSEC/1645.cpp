#include<bits/stdc++.h>
#define int long long
using namespace std;

bool pos(int arr[],int n,int x,int mid){
    int tot=0;
    for(int i=0;i<n;i++){
        tot+=(mid/arr[i]);
    }
    return tot>=x;
}


int32_t main()
{
    int n;
	cin >> n ;
	vector<int>ans(n,0);
	stack<pair<int,int>>s;
	for(int i=1;i<=n;i++)
	{
	    int t;
	    cin>>t;
	    if(!s.empty()){
	        while(!s.empty() && s.top().first>=t)s.pop();
	        if(!s.empty())ans[i-1]=s.top().second;
	    }
	    s.push({t,i});
	}
	for(auto v:ans)cout<<v<<" ";
	return 0;
}