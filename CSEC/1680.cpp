
// Problem : Longest Flight Route
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1680
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
// int maxN=200005;
int n,m;
int d[200005],par[200005];
vector<int>adj[200005];
void dfs(int node)
{
	for(auto child:adj[node])
	{
		if(d[child]<=d[node])
		{
			d[child]=d[node]+1;
			par[child]=node;
			dfs(child);
		}
	}
}
void solve(){
	cin>>n>>m;
	FOR(i,m){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
	}
	d[1]  = 1;
	par[1]=-1;
	dfs(1);
	if(d[n]==0)
	{
		cout<<"IMPOSSIBLE";
	}
	else
	{
		vlli ans;
		int NODE=n;
		while(NODE!=-1)
		{
			ans.pb(NODE);
			NODE=par[NODE];
		}
		reverse(all(ans));
		cout<<ans.size()<<endl;
		for(auto v:ans)
			cout<<v<<" ";
	}
	return;	
}


int32_t main() {
    	fast;
    	solve();
    return 0;
}
