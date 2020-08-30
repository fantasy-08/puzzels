
// Problem : C. Fox And Names
// Contest : Codeforces - Codeforces Round #290 (Div. 2)
// URL : https://codeforces.com/problemset/problem/510/C
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
int n;
vector<vint>adj;
vint T;
vint In;
set<int>s;
void topo(){
	queue<int>q;
	// vector<int>vis(26,0);
	FOR(i,26){
		if(In[i]==-1 && s.count(i))q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		T.pb(u);
		for(auto v:adj[u]){
			In[v]--;
			if(In[v]==0)q.push(v);
		}
	}
}
void solve(){
	In.resize(26,-1);
	rd(n);
	vector<string>arr(n);
	FOR(i,n)rd(arr[i]);
	adj.resize(26,vint());
	FOR(i,n-1){
		string A=arr[i], B=arr[i+1];
		int j = 0;
        while(j<A.length()&&j<B.length()&&A[j]==B[j])
            j++;
        if(j<A.length()&&j>=B.length()){
            pp("Impossible");
            return ;
        }
		FOR(j,(int)min(A.size(),B.size())){
			if(A[j]!=B[j]){
				s.insert(A[j]-'a'),s.insert(B[j]-'a');
				adj[(A[j]-'a')].pb(B[j]-'a');
				if(In[B[j]-'a']==-1)In[B[j]-'a']=1;
				else In[B[j]-'a']++;
				break;
			}
		}
	}
	topo();
	if(T.size()!=s.size() ){
		pp("Impossible");
		return ;
	}
	vector<int>vis(26,0);
	for(auto c:T)vis[c]=1;
	FOR(i,26){
		if(vis[i]==0){
			cout<<(char)(i+'a');
		}
	}
	for(auto c:T){
		cout<<(char)(c+'a');
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
