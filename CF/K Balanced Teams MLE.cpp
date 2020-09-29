
// Problem : E. K Balanced Teams
// Contest : Codeforces - Codeforces Round #544 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1133/E
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
vint arr;
int dp[5005][5005][2];
int n,m;
int go(int pos,int k,bool took)
{
	if(pos>=n || k<0)return 0;
	if(k==0 && took==false)return 0;
	if(dp[pos][k][took]!=-1)return dp[pos][k][took];
	if(pos==0)return dp[pos][k][took]=max(1+go(pos+1,k-1,true),go(pos+1,k,false));
	if(took)
	{
		if(arr[pos]-arr[pos-1]<5){
			return dp[pos][k][took]=1+go(pos+1,k,true);
		}
		if(k==0)return dp[pos][k][took]=0;
		return dp[pos][k][took]=max(1+go(pos+1,k-1,true),go(pos+1,k,false));
	}
	return dp[pos][k][took]=max(1+go(pos+1,k-1,true),go(pos+1,k,false));
}
void solve(){
	rd(n,m);
	arr.resize(n);
	FOR(i,n)rd(arr[i])	;
	sort(all(arr));
	pp(go(0,m,false));
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
