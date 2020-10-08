
// Problem : Cosmic Temple
// Contest : CodeChef - Learn CP with CodeChef - Trees and Graphs
// URL : https://www.codechef.com/UATG001/problems/COSTEMP
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
vector<vector<int>>adj;
vector<int>lvl,vis,par;
int LCA[1000001][20];
int n;

void dfs(int node,int p,int l)
{
	par[node]=p;
	lvl[node]=l;
	LCA[node][0]=p;
	for(auto child:adj[node])
	{
		if(child!=p)
		{
			dfs(child,node,l+1);	
		}
	}
}

void init()
{
	for(int i=1;i<20;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				LCA[j][i]=LCA[LCA[j][i-1]][i-1];
			}
		}
	}	
}

int lca(int a,int b){
	if(lvl[a]>lvl[b])swap(a,b);
	int d=lvl[b]-lvl[a];
	int f=0;
	while(d)
	{
		if(d&1)b=LCA[b][f];
		d>>=1;
		f++;
	}
	if(a==b)return a;
	for(int j=19;j>=0;j--)
	{
		if(LCA[a][j]!=-1 && LCA[a][j]!=LCA[b][j])
			a=LCA[a][j],b=LCA[b][j];
	}
	return LCA[a][0];
}
void solve(){
	rd(n);
	adj.resize(n+1,vector<int>());
	par.resize(n,-1),lvl.resize(n);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<20;j++){
			LCA[i][j]=-1;
		}
	}
	dfs(0,-1,0);
	init();
	for(int i=0;i<n;i++)
	{
		// Error(i,lvl[i]);
		int temp=0;
		for(int j=0;j<n;j++){
			if(j==i)continue;
			int D=lvl[i]+lvl[j]-2*lvl[lca(i,j)];
			temp+=D;
		}
		cout<<temp<<" ";
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
