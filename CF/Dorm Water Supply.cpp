
// Problem : A. Dorm Water Supply
// Contest : Codeforces - Codeforces Beta Round #83 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/107/A
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
vector<int>in;
map<pair<int,int>,int>cost;
pint dfs(int node){
	vis[node]=true;
	int cnt=0;
	int leaf=0;
	int temp=INT_MAX;
	for(auto child:adj[node]){
		if(!vis[child]){
			auto Y=dfs(child);
			int val=Y.ft;
			leaf=Y.se;
			temp=min({temp,val,cost[{node,child}]});
			cnt++;
		}
	}
	if(cnt==0)leaf=node;
	return {temp,leaf};
}
void solve(){
	int n,m;
	rd(n,m);
	adj.resize(n+1,vint());
	vis.resize(n+1,false);
	in.resize(n+1);
	FOR(i,m){
		int u,v,c;
		rd(u,v,c);
		if(u==v)continue;
		adj[u].pb(v);
		in[v]++;
		cost[{u,v}]=c;
	}
	vector<vint>ans;
	rep(i,1,n+1){
		if(in[i]==0){
			if(adj[i].size()==0)continue;
			auto temp=dfs(i);
			if(temp.ft==INT_MAX)temp.ft=0;
			ans.pb({i,temp.se,temp.ft});			
		}
	}
	pp(ans.size());
	for(auto c:ans){
		for(auto v:c){
			cout<<v<<" ";
		}
		cout<<endl;
	}
	return;	
	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
