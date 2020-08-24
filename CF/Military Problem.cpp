
// Problem : E. Military Problem
// Contest : Codeforces - Codeforces Round #498 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1006/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int n,q;
vector<vint>adj;
vector<int>subtree;
map<pair<int,int>,int>dp;
vector<int>val;
int sub(int node){
	int temp=0;
	if(adj[node].size()==0){
		subtree[node]=0;
		return 1;
	}
	for(auto child:adj[node])temp+=sub(child);
	subtree[node]=temp;
	return temp+1;
}
int query(int node,int k){
	if(subtree[node]<k)return -1;
	if(k==0)return node;
	if(dp.find({node,k})!=dp.end())return dp[{node,k}];
	for(auto child:adj[node]){
		if((subtree[child]+1)<k){
			k-=(subtree[child]+1);
		}
		else return dp[{node,k}]=query(child,k-1);		
	}
	return dp[{node,k}]=-1;
}
mint ind;
void dfs(int node){
	val.pb(node);
	ind[node]=val.size()-1;
	for(auto child:adj[node]){
		dfs(child);
	}	
}
void solve(){
	rd(n,q);
	adj.resize(n+1,vint());
	FOR(i,n-1){
		int u;
		rd(u);
		adj[u].pb(i+2);
	}	
	subtree.resize(n+1);
	sub(1);
	dfs(1);
	// rep(i,1,n+1)error(subtree[i]);
	FOR(i,q){
		int U,K;
		rd(U,K);
		K--;
		if(subtree[U]<K){
			pp(-1);
			continue;
		}
		int IND=ind[U]+K;
		if(IND>=val.size())pp(-1);
		else pp(val[IND]);
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
