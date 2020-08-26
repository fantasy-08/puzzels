
// Problem : D. Remove One Element
// Contest : Codeforces - Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1272/D
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
vint arr;
int dp[200002][3];
vector<int>ans;
int go(int pos,int flag){
	if(pos>=n)return 0;
	if(dp[pos][flag]!=-1)return dp[pos][flag];
	if(flag==0){
		return dp[pos][flag]=max(1+go(pos+1,1),go(pos+1,0));
	}
	if(flag==1){
		if(arr[pos-1]<arr[pos])return dp[pos][flag]=max(1+go(pos+1,flag),go(pos+1,2));
		return dp[pos][flag]=go(pos+1,2);
	}
	if(flag==2){
		if(arr[pos]>arr[pos-2]){
			return dp[pos][flag]=ans[pos];
		}
		return dp[pos][flag]=0;
	}
	return 0;
}
void solve(){
	rd(n);
	arr.resize(n);
	ans.resize(n);
	for(int& v:arr)rd(v);
	ans[n-1]=1;
	for(int i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1])ans[i]=1+ans[i+1];
		else ans[i]=1;
	}	
	pp(go(0,0));
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
