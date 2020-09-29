// Problem : A. The Two Routes
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/problemset/problem/601/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
map<int,set<int>>rail,road;

void solve(){
	int n,m;
	rd(n,m);

	FOR(i,m){
		int u,v;
		rd(u,v);
		rail[u].insert(v);
		rail[v].insert(u);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(rail[i].find(j)==rail[i].end()) road[i].insert(j);
		}
	}
	
	vector<int>time(n+1);
	vector<bool>vis(n+1);
	queue<pint>q;
	q.push({1,0});
	vis[1]=true;
	bool pos=false;
	vector<int>par(n+1);
	par[1]=-1;
	while(q.size())
	{
		auto Info=q.front();
		q.pop();
		int node=Info.ft;
		int dis=Info.se;
		if(node==n){
			pos=true;
			break;
		}
		for(auto child:rail[node]){
			if(!vis[child]){
				time[child]=dis+1;
				par[child]=node;
				vis[child]=true;
				q.push({child,dis+1});
			}
		}
	}
	if(pos==false){
		pp(-1);
		return ;
	}
	set<int>S;
	int Node=n;
	while(Node!=-1){
		S.insert(Node);
		Node=par[Node];
	}
	for(int i=1;i<=n;i++){
		if(S.find(i)!=S.end())continue;
		else time[i]=0;
	}
	
	vis.clear();
	vis.resize(n+1);
	
	vector<int>time2(n+1);
	queue<pint>Q;
	Q.push({1,0});
	vis[1]=true;
	pos=false;
	while(Q.size())
	{
		auto Info=Q.front();
		Q.pop();
		int node=Info.ft;
		int dis=Info.se;
		if(node==n){
			pos=true;
			break;
		}
		for(auto child:road[node]){
			if(!vis[child]){
				if(child!=1 || child!=n)
				{
					if(time[child]==dis+1)
					{
						continue;
					}
				}
				time2[child]=dis+1;
				vis[child]=true;
				Q.push({child,dis+1});
			}
		}
	}
	
	if(pos==false){
		pp(-1);
		return ;
	}
	pp(max(time[n],time2[n]));
	
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}

