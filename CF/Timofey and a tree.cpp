// Problem : A. Timofey and a tree
// Contest : Codeforces - Codeforces Round #395 (Div. 1)
// URL : https://codeforces.com/problemset/problem/763/A
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
int n;
vint color;
vector<bool>vis;
vector<vector<int>>adj;
bool chkDFS(int node,int c){
	vis[node]=true;
	if(color[node]!=c)return false;
	for(auto child:adj[node]){
		if(!vis[child]){
			int temp=chkDFS(child,c);
			if(!temp){
				return false;
			}
		}
	}
	return true;
}
bool dfs(int node){
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child]){
			int temp=chkDFS(child,color[child]);
			if(!temp)return false;
		}
	}
	return true;
}

void solve()
{
	rd(n);
	adj.clear();
	adj.resize(n+1,vint());
	vector<pair<int,int>>edge;
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		edge.pb({u,v});
		adj[u].pb(v);
		adj[v].pb(u);
	}
	color.resize(n+1);
	rep(i,1,n+1)rd(color[i]);
	if(n==2){
		pp("YES");
		pp(1);
		return ;
	}
	int cnt=0;
	for(auto edg:edge){
		if(color[edg.ft]==color[edg.se]){
			cnt++;
			continue;
		}
		vis.clear();
		vis.resize(n+1,false);
		if(dfs(edg.ft)){
			pp("YES");
			pp(edg.ft);
			return ;
		}
		vis.clear();
		vis.resize(n+1,false);
		if(dfs(edg.se)){
			pp("YES");
			pp(edg.se);
			return ;
		}
		pp("NO");
		return ;
	}
	if(cnt==n-1){
		pp("YES");
		pp(1);
		return ;
	}
	pp("NO");
	
	return;	
}


int32_t main() 
{
	fast;
	solve();
    return 0;
}
