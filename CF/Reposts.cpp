
// Problem : A. Reposts
// Contest : Codeforces - VK Cup 2015 - Qualification Round 1
// URL : https://codeforces.com/problemset/problem/522/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define plii pair< int,int >
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
map<string,vector<string>>adj;
map<string , bool >vis;
int dfs(string node){
	int sub_tree=0;
	vis[node]=true;
	for(auto child:adj[node]){
		// if(!vis[child])
			sub_tree=max(sub_tree,dfs(child));
	}
	return sub_tree+1;
}
void solve(){
	int n;
	rd(n);
	set<string>arr;
	FOR(i,n){
		string u,gb,v;
		rd(u,gb,v);
		FOR(j,u.size()){
			if(u[j]>='A' && u[j]<='Z')u[j]=(char)(u[j]-'A'+'a');
		}
		FOR(j,v.size()){
			if(v[j]>='A' && v[j]<='Z')v[j]=(char)(v[j]-'A'+'a');
		}
		adj[v].pb(u);
		arr.insert(u),arr.insert(v);
		vis[u]=false,vis[v]=false;
	}	
	int ans=0;
	for(auto word:arr){
		// if(!vis[word]){
			ans=max(ans,dfs(word));
		// }
	}
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
