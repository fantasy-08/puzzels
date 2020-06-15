
// Problem : Removing Digits
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1637
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
int dp[1000001];


int go(int s){
	if(s==0)return 0;
	if(dp[s]!=-1)return dp[s];
	int ans=INT_MAX;
	vector<bool>dig(10,false);
	int k=s;
	while(k){
		int l=k%10;
		dig[l]=true;
		k/=10;
	}
	rep(i,1,10){
		if(dig[i]==true && s-i>=0){
			ans=min(ans,1+go(s-i));
		}
	}
	return dp[s]=ans;
}


void solve(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<go(n);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
