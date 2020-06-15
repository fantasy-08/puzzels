
// Problem : Grid Paths
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1638
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

void solve(){
	int n;
	cin>>n;
	int arr[n][n];
	FOR(i,n){
		FOR(j,n){
			char t;
			cin>>t;
			if(t=='*')arr[i][j]=0;
			else arr[i][j]=1;
			// cout<<arr[i][j]<<" ";
		}
		// cout<<endl;
	}	
	if(arr[0][0]==0 || arr[n-1][n-1]==0){
		cout<<0;
		return;
	}
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		if(arr[0][i]==0)continue;
		else dp[0][i]=dp[0][i-1];
	}
	for(int i=1;i<n;i++){
		if(arr[i][0]==0)continue;
		else dp[i][0]=dp[i-1][0];
	}
	rep(i,1,n){
		rep(j,1,n){
			if(arr[i][j]==0){
				dp[i][j]=0;
				continue;
			}
			else dp[i][j]=(dp[i-1][j]%MOD+dp[i][j-1]%MOD)%MOD;
		}
	}
	// FOR(i,n){
		// FOR(j,n){
			// cout<<dp[i][j]<<" ";
		// }
		// cout<<endl;
	// }
	cout<<dp[n-1][n-1];
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
