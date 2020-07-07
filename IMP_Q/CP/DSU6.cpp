
// Problem : B. Coloring a Tree
// Contest : Codeforces - Codeforces Round #453 (Div. 2)
// URL : https://codeforces.com/problemset/problem/902/B
// Memory Limit : 256 MB
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
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
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
void dfs(int node,vector<int>adj[],int color,vlli& pre_color){
	pre_color[node]=color;
	for(auto child:adj[node]){
		if(pre_color[child]!=color){
			dfs(child,adj,color,pre_color);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vlli adj[n+1];
	rep(i,1,n){
		int v;
		cin>>v;
		adj[v].pb(i+1);
	}
	vlli color(n+2,0);
	rep(i,1,n+1)cin>>color[i];
	vlli pre_color(n+2,0);
	int ans=0;
	rep(i,1,n+1){
		if(pre_color[i]!=color[i]){
			ans++;
			dfs(i,adj,color[i],pre_color);
		}
	}
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
