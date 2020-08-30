
// Problem : C. Sloth Naptime
// Contest : Codeforces - AlgorithmsThread Tree Basics Contest
// URL : https://codeforces.com/gym/102694/problem/C
// Memory Limit : 256 MB
// Time Limit : 5000 ms
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
#define N 300005
#define MOD 1000000007
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int n;
vector<vint>adj;
int start[N],End[N],tree[2*N];
int LCA[N][20],level[N];
int timer=1;

void dfs(int node,int par,int l){
	level[node]=l;
	LCA[node][0]=par;
	tree[timer]=node;
	start[node]=timer++;
	for(auto child:adj[node]){
		if(child!=par){
			dfs(child,node,l+1);
		}
	}
	tree[timer]=node;
	End[node]=timer++;
}

void init_LCA()
{
	rep(j,1,20){
		rep(i,1,n+1){
			if(LCA[i][j-1]!=-1){
				LCA[i][j]=LCA[LCA[i][j-1]][j-1];
			}
		}
	}
}
int get_LCA(int a,int b){
	if(level[a]>level[b])swap(a,b);
	int d=level[b]-level[a];
	int f=0;
	while(d){
		if(d&1)b=LCA[b][f];
		d>>=1;
		f++;
	}
	if(a==b)return a;
	for(int j=19;j>=0;j--){
		if(LCA[a][j]!=-1 && (LCA[a][j]!=LCA[b][j])){
			a=LCA[a][j],b=LCA[b][j];
		}
	}
	return LCA[a][0];
}
void lift(int &n, int c) {
    for (int i = 19; i >= 0; i--)
        if (LCA[n][i] != -1 && c - (1 << i) >= 0)
            n = LCA[n][i], c -= (1 << i);
}
 
void solve(){
	timer=1;
	rd(n);
	adj.resize(n+1,vint());
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1,1);
	init_LCA();	
	int Q;
	rd(Q);
	FOR(T,Q)
	{
		int a,b,c;
		rd(a,b,c);
		int lca=get_LCA(a,b);
		if(level[a]+level[b]-2*level[lca]<=c)pp(b);
		else{
			int TA=level[a]-level[lca],TB=level[b]-level[lca];
			if(TA>=c){
				lift(a,c);
				pp(a);
			}	
			else{
				c-=TA;
				c=TB-c;
				lift(b,c);
				pp(b);
			}
		}
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

