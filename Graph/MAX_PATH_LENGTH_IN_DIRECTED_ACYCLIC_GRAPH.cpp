
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
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
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
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
vector<vector<int>>adj;
vector<bool>vis;
vector<int>dp;
int dfs(int node)
{
	int ans=0;
	vis[node]=true;
	dp[node]=0;
	for(auto child:adj[node])
	{
		if(!vis[child])
		{
			dfs(child);
		}
		dp[node]=max(dp[node],1+dp[child]);
	}
	return dp[node];
}
void solve(){
	int n,e;
	cin>>n>>e;
	adj.resize(n+1,vector<int>());
	vis.resize(n+1);
	dp.resize(n+1);
	FOR(i,e)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
	}
	int ans=0;
	rep(i,1,n+1)
	{
		if(!vis[i])
		{
			ans=max(ans,dfs(i));
		}
	}
	cout<<ans;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
