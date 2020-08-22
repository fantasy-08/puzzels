
// Problem : A. Xor-tree
// Contest : Codeforces - Codeforces Round #245 (Div. 1)
// URL : https://codeforces.com/contest/429/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
void dfs(int node,vector<int>&lvl,vint * adj,vector<bool>& vis,int l){
	vis[node]=true;
	lvl[node]=l;
	for(auto child:adj[node]){
		if(!vis[child])
			dfs(child,lvl,adj,vis,l+1);
	}
}
int ans=0;
vector<int>Ans;
void cal(int node,vector<int>&lvl,vint * adj,vector<bool>& vis,bool odd,bool even,vint& prev,vint& curr){
	int c=prev[node];
	if(odd && lvl[node]&1)c=1-c;
	else if(even && lvl[node]%2==0)c=1-c;
	vis[node]=true;
	if(c!=curr[node]){
		ans++;
		Ans.pb(node);
		if(lvl[node]&1)odd=odd?false:true;
		else even=even?false:true;
	}	
	for(auto child:adj[node]){
		if(!vis[child])
			cal(child,lvl,adj,vis,odd,even,prev,curr);
	}
}
void solve(){
	int n;
	rd(n);
	vint level(n+1,0);
	vint adj[n+1];
	vector<bool>vis(n+1);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	vint prev(n+1),curr(n+1);
	rep(i,1,n+1)rd(prev[i]);
	rep(i,1,n+1)rd(curr[i]);
	dfs(1,level,adj,vis,0);
	vis.clear();
	vis.resize(n+1);
	cal(1,level,adj,vis,false,false,prev,curr);
	pp(ans);
	for(auto v:Ans)pp(v);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
