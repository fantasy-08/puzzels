
// Problem : C. Uncle Bogdan and Country Happiness
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
vector<int>scr,p,vis;
vector<vint>adj;
int n,tot;
bool ans;
pair<int,int>dfs(int node)
{
	if(ans==false)
	{
		pint A={0,0};
		return A;
	}
	vis[node]=true;
	pint D={0,0};
	int cnt=0;
	for(auto child:adj[node]){
		if(!vis[child]){
			cnt++;
			auto T=dfs(child);
			// if(child==3){
				// Error(T.ft,T.se);
			// }
			D.ft+=T.ft;
			D.se+=T.se;
		}
	}
	if(cnt==0){
		int k=p[node]+scr[node];
		if(k%2!=0){
			ans=false;
		}
		pint A={k/2,k/2-scr[node]};
		if(A.ft<0 || A.se<0)ans=false;
		// Error(A.ft,A.se);
		return A;
	}
	else
	{
		int S=D.ft+D.se+p[node];
		int Dif=scr[node];
		int good=S+Dif;
		if(good&1){ans=false;}
		pint A={good/2,(good/2)-scr[node]};
		if(A.ft<D.ft)ans=false;
		if(A.ft<0 || A.se<0)ans=false;
		return A;
	}
}
void solve(){
	rd(n,tot);
	scr.clear(),p.clear(),vis.clear(),adj.clear();
	adj.resize(n+1,vint()),vis.resize(n+1),scr.resize(n+1),p.resize(n+1);
	rep(i,1,n+1)rd(p[i]);
	rep(i,1,n+1)rd(scr[i]);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans=true;
	dfs(1);
	if(ans)pp("YES");
	else pp("NO");
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
