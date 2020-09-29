
// Problem : C. Checkposts
// Contest : Codeforces - Codeforces Round #244 (Div. 2)
// URL : https://codeforces.com/problemset/problem/427/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vint vector<int>
#define sint set<int>
#define mint map<int,int>
#define pint pair< int,int >
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define precision(x) cout<<fixed<<setprecision(x);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
vector<vector<int>>adj,tr;
vector<int>c;
vector<int>a;
vector<bool>vis;
void dfs(int node)
{
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child])
			dfs(child);
	}
	a.pb(node);
}
int dfs1(int node,map<int,int>&sc){
	vis[node]=true;
	for(auto child:tr[node]){
		if(!vis[child]){
			dfs1(child,sc);
		}
	}
	sc[c[node]]++;
}
void solve(){
	int n;
	rd(n);
	c.resize(n+1);
	adj.resize(n+1,vint());
	tr.resize (n+1,vint());
	vis.resize(n+1);
	rep(i,1,n+1)rd(c[i]);
	int m;
	rd(m);
	FOR(i,m){
		int  u,v;
		rd(u,v);
		adj[u].pb(v);
		tr[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	vis.clear();
	vis.resize(n+1);
	int ans=0,val=1;
	int i=a.size()-1;
	while(i>=0){
		if(vis[a[i]]==false){
			mint sc;
			dfs1(a[i],sc);
			for(auto v:sc)
			{
				ans+=v.ft,val*=v.se;
				break;				
			}
		}
		i--;
	}
	pp(ans,val);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
