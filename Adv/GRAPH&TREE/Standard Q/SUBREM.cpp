
// Problem : Subtree Removal
// Contest : CodeChef - Learn CP with CodeChef - Trees and Graphs
// URL : https://www.codechef.com/UATG001/problems/SUBREM
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
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
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

int dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&w,int k)
{
	vis[node]=true;
	int temp=-k;
	int temp2=w[node];
	for(auto child:adj[node])
	{
		if(!vis[child])
		{
			temp2+=dfs(child,adj,vis,w,k);
		}		
	}
	// error(node);
	// Error(temp,temp2);
	return max(temp,temp2);
}
void solve(){
	int n,x;
	rd(n,x);
	vector<int>W(n+1);
	rep(i,1,n+1)rd(W[i]);
	vector<vector<int>>adj(n+1,vector<int>());
	rep(i,1,n){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	vector<bool>vis(n+1);
	pp(dfs(1,adj,vis,W,x));
	return;	
}


int32_t main() {
    fint{
    	// fast;
    	solve();
    }
    return 0;
}
