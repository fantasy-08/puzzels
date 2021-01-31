
// Problem : E - Magical Ornament
// Contest : AtCoder - AtCoder Beginner Contest 190
// URL : https://atcoder.jp/contests/abc190/tasks/abc190_e
// Memory Limit : 1024 MB
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
#define maxN 100005
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
vector<int>adj[maxN];
vector<int>req;
int n,e,k;
int dis[maxN][18];
int dp[18][200000];
int go(int prev,int bit)
{
	if(dp[prev][bit]!=-1)return dp[prev][bit];
	if(bit==0)
	{
		int ans=INT_MAX;
		for(int i=0;i<k;i++){
			ans=min(ans,go(i,bit|(1<<i))+1);
		}
		return dp[prev][bit]=ans;
	}
	int ans=INT_MAX;
	for(int i=0;i<k;i++){
		if(bit&(1<<i))continue;
		int temp=dis[req[prev]][i]+go(i,bit|(1<<i));
		ans=min(ans,temp);
	}
	if(ans==INT_MAX) return dp[prev][bit]=0;
	return dp[prev][bit]=ans;
}
void bfs(int Node,int A)
{
	rep(i,1,n+1)dis[i][A]=-1;
	
	dis[Node][A]=0;
	
	queue<int>q;
	q.push(Node);
	
	while(q.size())
	{
		int node=q.front();
		q.pop();
		
		for(auto child:adj[node]){
			if(dis[child][A]==-1){
				dis[child][A]=dis[node][A]+1;
				q.push(child);
			}
		}
	}
}
void solve(){
	rd(n,e);
	FOR(i,e)
	{
		int a,b;
		rd(a,b);
		adj[a].pb(b),adj[b].pb(a);
	}
	
	rd(k);
	FOR(i,k){
		int t;
		rd(t);
		req.pb(t);
	}
	
	FOR(i,k){
		bfs(req[i],i);
	}	
	
	for(int i = 0 ; i < k ; ++i)
	{
		if(dis[req[0]][i] == -1)
			{cout<<-1<<"\n"; return ;}
	}
	memset(dp,-1,sizeof(dp));
	int ans=go(0,0);
	
	pp(ans);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
