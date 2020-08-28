
// Problem : C. The Fair Nut and String
// Contest : Codeforces - Codeforces Round #526 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1084/C
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
string s;
int dp[100001][2][2];
int go(int pos,bool a,bool taken){
	if(pos==s.size())
		if(taken)return 1;
		else return 0;
	if(dp[pos][a][taken]!=-1)return dp[pos][a][taken];
	if(!taken){
		if(s[pos]=='a')return dp[pos][a][taken]=(go(pos+1,false,true)%MOD+go(pos+1,a,false)%MOD)%MOD;
		return dp[pos][a][taken]=go(pos+1,a,false)%MOD;
	}
	if(a){
		if(s[pos]=='a')return dp[pos][a][taken]=(go(pos+1,false,taken)%MOD+go(pos+1,a,taken)%MOD)%MOD;
		return dp[pos][a][taken]=go(pos+1,a,taken)%MOD;
	}
	if(s[pos]=='b')return dp[pos][a][taken]=(go(pos+1,true,taken))%MOD;
	return dp[pos][a][taken]=go(pos+1,a,taken)%MOD;
}
void solve(){
	rd(s);
	pp(go(0,true,false));
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
