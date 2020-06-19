
// Problem : Course Schedule
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1679
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;

void solve(){
	int n,e;
	cin>>n>>e;
	vector<int>adj[n+1];
	vector<int>in(n+1,0);
	FOR(i,e){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		in[v]++;
	}
	vector<int>ans;
	queue<int>q;
	rep(i,1,n+1)
		if(in[i]==0)
			q.push(i);
	if(q.size()==0)
	{
		cout<<"IMPOSSIBLE";
		return ;
	}
	while(q.size())
	{
		int node=q.front();
		q.pop();
		ans.pb(node);
		for(auto child:adj[node])
		{
			in[child]--;
			if(in[child]==0)q.push(child);
		}
	}
	if(ans.size()!=n){
		cout<<"IMPOSSIBLE";
		return ;
	}
	for(auto v:ans)cout<<v<<" ";
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
