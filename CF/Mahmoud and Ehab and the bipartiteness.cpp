
// Problem : B. Mahmoud and Ehab and the bipartiteness
// Contest : Codeforces - Codeforces Round #435 (Div. 2)
// URL : https://codeforces.com/problemset/problem/862/B
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
vint vis;
vint color;
int n;
map<int,sint> adj;
set<int>Red,Blue;
void Color(int node,int c){
	vis[node]=true;
	color[node]=c;
	if(c)Red.insert(node);
	else Blue.insert(node);
	for(auto child:adj[node]){
		if(!vis[child])
			Color(child,1-c);
	}
}
int Count(int node){
	int c=color[node],edge=0;
	set<int>chk=c?Blue:Red;
	for(auto child:chk){
		if(adj[node].find(child)!=adj[node].end())continue;
		edge++;
		adj[node].insert(child);
		adj[child].insert(node);
	}
	return edge;
}
void solve(){
	rd(n);
	int ans=0;
	vis.resize(n+1);
	color.resize(n+1,-1);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	Color(1,0);
	vis.clear();
	vis.resize(n+1);
	int ideal=(Red.size()*Blue.size());
	pp(ideal-(n-1));
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
