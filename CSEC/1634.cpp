
// Problem : Minimizing Coins
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1634
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
// int n,t;
// int arr[101];
// int dp[1000001][101];
// int go(int s,int i){
	// if(s==t)return 0;
	// if(s>t)return INT_MAX;
	// if(dp[s][i]!=-1)return dp[s][i];
	// int ans=INT_MAX;
	// for(int j=i;j<n;j++){
		// ans=min(ans,1+go(s+arr[j],j));
	// }
	// return dp[s][i]=ans;
// }
void solve(){
	int n, target;
  cin >> n >> target;
  vector<int> c(n);
  for (int&v : c) cin >> v;

  vector<int> dp(target+1,1e9);
  dp[0] = 0;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i-c[j] >= 0) {
	dp[i] = min(dp[i], dp[i-c[j]]+1);
      }
    }
  }
  cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
