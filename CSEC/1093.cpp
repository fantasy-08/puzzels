// Problem : Two Sets II
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1093
// Memory Limit : 512 MB
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
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
int n,k;
int dp[501][70000];
int go(int i,int s){
	if(s==k)return 1;
	if(s>k)return 0;
	if(i>=n)return 0;
	if(dp[i][s]!=-1)return dp[i][s];
	return dp[i][s]=(go(i+1,s)%MOD+go(i+1,s+i)%MOD)%MOD;
}
 
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	k=(n*(n+1))/4;
	int y=(n*(n+1))/2;
	if(y&1){
		cout<<0<<endl;
		return;
	}
	cout<<(go(1,0))%MOD;
	return;	
}
 
 
int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}