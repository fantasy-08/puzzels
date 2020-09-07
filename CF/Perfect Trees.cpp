
// Problem : Perfect Trees
// Contest : CodeChef - CodeOverflow 1.2
// URL : https://www.codechef.com/COVO2020/problems/COV2TREE
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
int n;
vint score(100005);
vector<vint>adj;
vector<bool>vis(100005);
int min_dis,ans;
map<int,pair<int,int>> dfs(int node,int lvl)
{
	vis[node]=true;
	map<int,pair<int,int>>temp;
	for(auto child:adj[node]){
		if(!vis[child])
		{
			map<int,pair<int,int>>T=dfs(child,lvl+1);
			for(auto v:T)
			{
				int num=v.ft*score[node];
				int Num=sqrt(num);
				Num*=Num;
				if(Num==num)
				{
					ans+=v.se.ft;
					min_dis=min(min_dis,abs(lvl-v.se.se));
				}
				if(temp.find(v.ft)==temp.end()){
					temp[v.ft]=v.se;
				}
				else{
					temp[v.ft].ft+=v.se.ft;
					temp[v.ft].se=min(temp[v.ft].se,v.se.se);
				}
			}
		}
	}
	if(temp.find(score[node])!=temp.end()){
		temp[score[node]].ft+=1;
		temp[score[node]].se=lvl;
	}
	else{
		temp[score[node]]={1,lvl};
	}
	return temp;
}
void solve(){
	rd(n);
	rep(i,1,n+1){
		adj[i].clear();
		vis[i]=false;
	}
	min_dis=1e9,ans=0;
	rep(i,1,n+1)rd(score[i]);
	FOR(i,n-1)
	{
		int u,v;
		rd(u,v);
		adj[u].pb(v),adj[v].pb(u);
	}
	dfs(1,0);
	if(ans==0)pp(0);
	else 
	pp(ans,min_dis);	
	return;	
}


int32_t main() {
	adj.resize(100005,vint());
    fint{
    	solve();
    }
    return 0;
}

