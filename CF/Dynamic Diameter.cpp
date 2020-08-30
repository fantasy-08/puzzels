
// Problem : B. Dynamic Diameter
// Contest : Codeforces - AlgorithmsThread Tree Basics Contest
// URL : https://codeforces.com/gym/102694/problem/B
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
int n;
vector<vint>adj;
vector<bool>vis;
set<int>inc;
int diameter;
void dfs(int node,int dis){
	int cnt=0;
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child]){
			dfs(child,dis+1),cnt++;
		}
	}
	if(cnt==0 && dis>diameter){
		diameter=dis;
		inc.clear();
		inc.insert(node);
	}
	else if(cnt==0 && dis==diameter){
		inc.insert(node);
	}
}
void dfs2(int node,int dis){
	int cnt=0;
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child]){
			dfs(child,dis+1),cnt++;
		}
	}
	 if(cnt==0 && dis==diameter){
		inc.insert(node);
	}
}
pint far(int node){
	int temp_dis=0,cnt=0;
	pair<int,int>dis;
	vis[node]=true;
	for(auto child:adj[node]){
		if(!vis[child]){
			cnt++;
			auto temp=far(child);
			if(temp_dis<=temp.ft){
				temp_dis=temp.ft;
				dis=temp;
			}
		}
	}
	if(cnt==0) return {0,node};
	dis.ft+=1;
	return 	dis;
}
void solve(){
	rd(n);
	adj.resize(n+1,vint());
	vis.resize(n+1,false);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int Leaf=far(1).se;	
	vis.clear();
	vis.resize(n+1,false);
	diameter=0;
	dfs(Leaf,0);
	if(inc.size()){
		vis.clear();
		vis.resize(n+1,false);
		dfs2(*inc.begin(),0);
	}
	inc.insert(Leaf);
	rep(i,1,n+1){
		// cout<<i<<" ";
		if(inc.count(i))pp(diameter+1);
		else pp(diameter);
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
