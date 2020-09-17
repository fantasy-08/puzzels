
// Problem : A. String Transformation 1
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1383/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int node){
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
void solve(){
	int n;
	rd(n);
	string A,B;
	rd(A,B);
	adj.clear(),vis.clear();
	adj.resize(20,vint());
	vis.resize(20);
	int cnt=0;
	FOR(i,n)
	{
		if(A[i]!=B[i])
		{
			if(A[i]>B[i]){
				pp(-1);
				return ;
			}
			adj[B[i]-'a'].pb(A[i]-'a');
			adj[A[i]-'a'].pb(B[i]-'a');
		}		
	}
	rep(i,0,20)
	{
		if(vis[i]==0){
			cnt++;
			dfs(i);
		}
	}
	pp(20-cnt);
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
