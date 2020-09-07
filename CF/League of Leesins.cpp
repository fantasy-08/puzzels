
// Problem : C. League of Leesins
// Contest : Codeforces - Codeforces Round #601 (Div. 2)
// URL : https://codeforces.com/contest/1255/problem/C
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
vector<bool>vis,vis2;
vector<int>temp;
int getLeaf(int node)
{
	vis2[node]=true;
	int cnt=0,ans=-1;
	for(auto child:adj[node]){
		if(!vis2[child]){
			cnt++;
			int T=getLeaf(child);
			ans=max(ans,T);
		}
	}
	if(cnt==0)return node;
	return ans;
}
void dfs(int node)
{
	vis[node]=true;
	temp.pb(node);
	for(auto child:adj[node]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
void solve(){
	int n;
	rd(n);
	adj.resize(n+1);
	vis.resize(n+1),vis2.resize(n+1);
	map<pair<int,int>,vector<int>>A;
	vector<pair<int,int>>F;
	set<int>uni;
	FOR(i,n-2)
	{
		int arr[3];
		FOR(j,3)rd(arr[j]);
		FOR(j,2){
			for(int k=j+1;k<3;k++){
				int u=arr[j],v=arr[k],z;
				if(arr[j]>arr[k])swap(u,v);
				FOR(m,3){
					if(m!=k && m!=j){z=arr[m];break;}
				}
				// pp(u,v,z);
				A[{u,v}].pb(z);
				if(A[{u,v}].size()==2){
					F.pb({u,v});
					uni.insert(u),uni.insert(v);
					adj[u].pb(v);
					adj[v].pb(u);
				}
			}
		}
	}
	vector<vector<int>>G;
	for(auto node:uni){
		if(!vis[node]){
			temp.clear();
			int X=getLeaf(node);
			dfs(X);
			G.pb(temp);
		}
	}
	/*for(auto v:A){
		cout<<v.ft.ft<<" "<<v.ft.se<<"-";
		for(auto c:v.se)cout<<c<<" ";
		cout<<endl;
	}*/
	for(auto a:G){
		int u=a[0],v=a[1];
		if(u>v)swap(u,v);
		vint term(A[{u,v}]);
		// for(auto v:term)error(v);
		if(a.size()==2){
			cout<<term[0]<<" "<<a[0]<<" "<<a[1]<<" "<<temp[1]<<" ";
		}
		else{
			int st=term[0];
			if(term[0]==a[2] || term[0]==a[1] || term[0]==a[0])st=term[1];
			cout<<st<<" ";
			for(auto v:a)cout<<v<<" ";
			u=a[a.size()-1],v=a[a.size()-2];
			if(u>v)swap(u,v);
			term=A[{u,v}];
			st=term[0];
			if(term[0]==a[a.size()-1] || term[0]==a[a.size()-2] || term[0]==a[a.size()-3])st=term[1];
			cout<<st<<" ";
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
