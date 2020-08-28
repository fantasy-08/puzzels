
// Problem : B. Dima and a Bad XOR
// Contest : Codeforces - Codeforces Round #553 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1151/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n,m;
vector<vint>a;
int dp[501][1025];
bool go(int pos,int x){
	if(pos==n){
		if(x)dp[pos][x]=1;
		return x;
	}
	if(dp[pos][x]!=-1)return dp[pos][x];
	for(int i=0;i<m;i++){
		if(go(pos+1,x^a[pos][i])){
			dp[pos][x]=1;
			return true;
		}	
	}
	dp[pos][x]=0;
	return false;
}
void solve(){
	rd(n,m);
	a.resize(n,vint(m));
	FOR(i,n){
		FOR(j,m){
			rd(a[i][j]);
		}
	}
	bool ans=go(0,0);
	if(!ans){
		pp("NIE");
	}
	else {
		pp("TAK");
		vector<int>ans;
		for(int i=n;i>=1;i--){
			FOR(j,1024){
				if(dp[i][j]==1){
					for(int k=0;k<m;k++){
						if(dp[i-1][j^a[i-1][k]]==1){
							ans.pb(k+1);
							break;
						}
					}
					break;
				}
			}
		}
		reverse(all(ans));
		for(auto v:ans)cout<<v<<" ";				
	}
	return;	
}


int32_t main() {
    // fint{
    	memset(dp,-1,sizeof(dp));
    	fast;
    	solve();
    // }
    return 0;
}

