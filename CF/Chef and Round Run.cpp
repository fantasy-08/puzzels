
// Problem : Chef and Round Run
// Contest : CodeChef - Practice(Easy)
// URL : https://www.codechef.com/problems/CHEFRRUN
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
vector<int>val,ssc;
vector<vint>adj,iv;
int n;
void dff(int node,vector<bool>&vis)
{
	vis[node]=true;
	for(auto child:adj[node])
	{
		if(!vis[child])
		{
			dff(child,vis);
		}
	}
	val.pb(node);
}
void dfs(int node,vector<bool>&vis)
{
	vis[node]=true;
	for(auto v:iv[node])
	{
		if(!vis[v])
		{
			dfs(v,vis);
		}		
	}
	ssc.pb(node);
}
void solve(){
	rd(n);
	adj.clear();
	iv.clear();
	val.clear();
	adj.resize(n+1,vint());
	iv.resize(n+1,vint());
	
	vint arr(n+1);
	rep(i,1,n+1)
	{
		int skip;
		rd(skip);
		skip%=n;
		int val1=i+skip;
		val1%=n;
		adj[i].pb(val1+1);
		iv[val1+1].pb(i);
		// Error(i,val+1);	
	}
	
	vector<bool>vis(n+1);
	rep(i,1,n+1)
	{
		if(!vis[i])
		{
			// val.pb(i);
			dff(i,vis);
		}
	}
	vis.clear();
	vis.resize(n+1);
	
	reverse(all(val));
	// rep(i,1,n+1)
	// {
		// cout<<i<<"->";
		// for(auto v:adj[i])
		// {
			// cout<<v<<" ";
		// }
		// cout<<endl;
	// }
// 	
	int ans=0;
	for(auto v:val)
	{
		if(!vis[v])
		{
			ssc.clear();
			dfs(v,vis);
			if(ssc.size()==1 && ssc[ssc.size()-1]!=adj[ssc[0]][0])continue;
			// for(auto v:ssc)
			// {
				// cout<<v<<" ";
			// }
			// cout<<endl;
			ans+=ssc.size();
			
		}
	}
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    	// error("hi");
    }
    return 0;
}
