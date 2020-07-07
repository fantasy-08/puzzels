
// Problem : E. Cyclic Components
// Contest : Codeforces - Codeforces Round #479 (Div. 3)
// URL : https://codeforces.com/problemset/problem/977/E
// Memory Limit : 256 MB
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
vector<bool>vis;
bool chk,chk2;
void dfs(int node,int par,vlli adj[]){
	vis[node]=true;
	if(adj[node].size()>2)chk2=true;
	for(auto child:adj[node]){
		if(vis[child]==false){
			dfs(child,node,adj);
		}
		else{
			if(child!=par) chk=true;
		}
	}
}


void solve(){
	int n,e;
	cin>>n>>e;
	vlli adj[n+1];
	vis.clear();
	vis.resize(n+1,false);
	while(e--){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	int ans=0;
	rep(i,1,n+1){
		if(vis[i]==false){
			chk=false;
			chk2=false;
			dfs(i,-1,adj);
			if(chk && !chk2){
				ans++;
				// error(i);
			}
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
