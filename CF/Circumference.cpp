
// Problem : A. Circumference of a Tree
// Contest : Codeforces - AlgorithmsThread Tree Basics Contest
// URL : https://codeforces.com/gym/102694/problem/A
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
int ans=0;
int diameter(int node){
	vint v;
	vis[node]=true;
	int sum=0;
	for(auto child:adj[node]){
		if(vis[child]==false){
			v.pb(diameter(child));
			// sum+=v[v.size()-1];
		}
	}
	// ans=max(ans,sum);
	sort(all(v),greater<int>());
	if(v.size()>1)
	ans=max(ans,v[0]+v[1]);
	if(v.size()==1)
	ans=max(ans,v[0]);
	if(v.size()==0){
		return 1;
	}
	
	return 1+*max_element(all(v));
}
void solve(){
	int n;
	rd(n);
	adj.resize(n+1,vint());
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	vis.resize(n+1);
	diameter(1);
	pp(3*ans);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
