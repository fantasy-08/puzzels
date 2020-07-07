
// Problem : Flight Discount
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1195
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
#define present(container, element) (container.find(element)!=container.end())
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
	int n,m;
	cin>>n>>m;
	map<pair<int,int>,int>COST;
	vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
	FOR(i,m){
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		COST[{u,v}]=w;
		adj[u].pb({v,w});
	}
	vector<int>dist(n,INT_MAX);
	vector<int>par(n,-1);
	dist[0]=0;
	set<pair<int,int>>s;
	s.insert({0,0});
	while(s.size())
	{
		auto P=*s.begin();
		s.erase(s.begin());
		int node  =P.se;
		for(auto PAIR:adj[node])
		{
			int child=PAIR.ft;
			int weight=PAIR.se;
			if(dist[child]!=INT_MAX && dist[child]>weight+dist[node])
			{
				s.erase(s.find({dist[child],child}));
			}
			if(dist[child]>weight+dist[node])
			{
				dist[child]=weight+dist[node];
				par[child]=node;
				s.insert({dist[child],child});
			}	
		}
	}
	// error(n);
	// rep(i,0,n)cerr<<par[i]<<" ";
	vector<int>path;
	int NODE=n-1;
	while(NODE!=-1)
	{
		path.pb(NODE);
		NODE=par[NODE];
	}
	reverse(all(path));
	vlli val;
	FOR(i,path.size()-1){
		int u=path[i];
		int v=path[i+1];
		val.pb(COST[{u,v}]);
	}
	auto it=max_element(all(val));
	*it=*it/2;
	int sum=0;
	for(auto v:val)sum+=v;
	cout<<sum;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
