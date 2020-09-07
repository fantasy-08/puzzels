
// Problem : D. Captain Flint and Treasure
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/D
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
vector<vint>adj;
vector<bool>vis;
vector<int>scr,ind;
int ans=0;
vector<int>pos,neg,in,val;
void dfs(int node)
{
	vis[node]=1;
	for(auto child:adj[node]){
		if(!vis[node]) dfs(child);
	}
	ans+=scr[node];
	if(ind[node]!=-1 && scr[node]>0){
		if(vis[ind[node]])ans-=scr[ind[node]];
		scr[ind[node]]+=scr[node];
		if(vis[ind[node]])ans+=scr[ind[node]];
	}
	if(scr[node]>0)pos.pb(node);
	else neg.pb(node);
}
void solve(){
	int n;
	rd(n);
	scr.clear(),vis.clear(),ind.clear();
	scr.resize(n+1),vis.resize(n+1),ind.resize(n+1),adj.resize(n+1,vint()),in.resize(n+1);
	rep(i,1,n+1)rd(scr[i]);
	rep(i,1,n+1){
		rd(ind[i]);
		if(ind[i]!=-1)adj[i].pb(ind[i]),in[ind[i]]++;
	}
	// rep(i,1,n+1)cout<<in[i]<<" ";
	// cout<<endl;
	queue<int>q;
	rep(i,1,n+1)if(in[i]==0)q.push(i),vis[i]=true;
	while(q.size()){
		int node=q.front();
		q.pop();
		val.pb(node);
		ans+=scr[node];
		if(ind[node]!=-1 && scr[node]>0){
			scr[ind[node]]+=scr[node];
			in[ind[node]]--;
			if(in[ind[node]]==0)q.push(ind[node]);
		}
		else if(ind[node]!=-1){
			in[ind[node]]--;
			if(in[ind[node]]==0)q.push(ind[node]);
		}
		if(scr[node]>0)pos.pb(node);
		else neg.pb(node);
	}
	pp(ans);
	// for(auto v:val)cout<<v<<" ";
	// return ;
	reverse(all(neg));
	for(auto v:pos)cout<<v<<" ";
	for(auto v:neg)cout<<v<<" ";
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
