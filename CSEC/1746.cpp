
// Problem : Array Description
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1746
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
int n,m;
int arr[100001];
int dp[100001][101];
int go(int pos,int prev){
	if(pos==n)return 1;
	if(dp[pos][prev]!=-1)return dp[pos][prev];
	if(pos==0){
		if(arr[pos]==0){
			int ans=0;
			rep(i,1,m+1){
				ans+= go(pos+1,i);
				if(ans>=MOD)ans-=MOD;
			}
			return dp[pos][prev]=ans%MOD;
		}
		else{
			return dp[pos][prev]=go(pos+1,arr[0])%MOD;
		}
	}
	if(arr[pos]!=0){
		if(abs(arr[pos]-prev)>1)return 0;
		return dp[pos][prev]=go(pos+1,arr[pos])%MOD;
	}
	//arr[pos]==0
	//-1 0 +1
	int ans=0;
	for(int i=-1;i<=1;i++){
		int k=prev+i;
		if(k>=1 && k<=m){
			ans+=go(pos+1,k);
			if(ans>=MOD)ans-=MOD;
		}
	}
	return dp[pos][prev]=ans%MOD;
	
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	FOR(i,n)cin>>arr[i];	
	cout<<go(0,0);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
