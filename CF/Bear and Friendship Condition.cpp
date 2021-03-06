
// Problem : A. Bear and Friendship Condition
// Contest : Codeforces - VK Cup 2017 - Round 1
// URL : https://codeforces.com/problemset/problem/771/A
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
vector<vint>adj;
vector<bool>vis;
int dfs(int node){
	int temp=1;
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child])
			temp+=dfs(child);
	}
	return temp;
}
void solve(){
	int n,m;
	rd(n,m)	;
	adj.resize(n+1,vint());
	FOR(i,m){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vis.resize(n+1,false);
	int tot=0;
	rep(i,1,n+1){
		if(vis[i]==false){
			int node=dfs(i);
			tot+=((node)*(node-1))/2;
		}
	}
	if(tot==m){
		pp("YES");
	}
	else pp("NO");
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
