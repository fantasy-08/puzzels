
// Problem : A. Fair
// Contest : Codeforces - Codeforces Round #485 (Div. 1)
// URL : https://codeforces.com/problemset/problem/986/A
// Memory Limit : 512 MB
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
#define plii pair< int,int >
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

void solve(){
	int n,m,k,s;
	rd(n,m,k,s);
	map<int,int>color;
	map<int,vector<int>>group;
	FOR(i,n){
		int t;
		cin>>t;
		group[t].pb(i+1);
		color[i+1]=t;
	}
	vector<int>adj[n+1];
	FOR(i,m){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<vector<int>>dis(n+1,vector<int>(k+1,-1));
	for(auto type : group)
	{
		int C=type.ft;
		queue<int>q;
		for(auto node:type.se){
			q.push(node);
			dis[node][C]=0;
		}
		while(q.size()){
			int node=q.front();
			q.pop();
			for(auto child:adj[node]){
				if(dis[child][C]==-1){
					dis[child][C]=dis[node][C]+1;
					q.push(child);
				}
			}
		}
	}
	rep(i,1,n+1){
		sort(all(dis[i]));
		int sum=0;
		rep(j,1,s+1)sum+=dis[i][j];
		cout<<sum<<" ";
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
