
// Problem : High Score
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1673
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

void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<pair<int,int>,int>>arr;
	FOR(i,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		// cerr<<u<<" "<<v<<" "<<w<<endl;
		arr.pb({{u,v},-w});
	}	
	vector<int>dist(n+1,INT_MAX);
	dist[1]=0;
	rep(i,1,n)
	{
		rep(j,0,m)
		{
			int u=arr[j].ft.ft;
			int v=arr[j].ft.se;
			int w=arr[j].se;
			// cerr<<u<<" "<<v<<" "<<w<<endl;
			if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
				dist[v]=dist[u]+w;
			// rep(i,1,n+1)cerr<<dist[i]<<" ";
			// cerr<<endl;
		}
	}
	int k=dist[n];
	bool flag=false;
	rep(i,0,m)
	{
		int u=arr[i].ft.ft;
		int v=arr[i].ft.se;
		int w=arr[i].se;
		if(dist[u]!=INT_MAX && dist[u]+w<dist[v])dist[v]=dist[u]+w,flag=true;
		
	}
	// error(flag);
	// cerr<<k<<" "<<dist[n];
	if(flag || k!=dist[n]){
		cout<<-1;
		return ;
	}
	cout<<-dist[n];
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
