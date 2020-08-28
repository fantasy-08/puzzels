// Problem : C. Ayoub and Lost Array
// Contest : Codeforces - Codeforces Round #533 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1105/C
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
vector<int> arr(3);
int n,l,r;
int dp[200002][3];
pair<bool,int> go(int pos,int rem){
	if(pos==n){
		return {rem==0,1};
	}
	if(dp[pos][rem]!=-1)return {true,dp[pos][rem]};
	int temp=0;
	FOR(i,3){
		auto info=go(pos+1,(rem+i)%3);
		if(info.ft)temp=(temp%MOD+((arr[i]%MOD)*(info.se%MOD)))%MOD;
	}
	dp[pos][rem]=temp%MOD;
	return {true,temp%MOD};
	
}
void solve(){
	rd(n,l,r);
	int total=r-l+1;
	// arr[0]=total/3;
	// arr[1]=arr[0],arr[2]=arr[1];
	
	arr[0]=(r/3)-ceil(l/3.0)+1;
	arr[1]=((r-1)/3)-ceil((l-1)/3.0)+1;	
	arr[2]=((r-2)/3)-ceil((l-2)/3.0)+1;		
	if(l==r){
		arr[0]=(l%3==0);
		arr[1]=(l%3==1);
		arr[2]=(l%3==2);
	}
	// FOR(i,total%3)arr[i]++;
	// pp(arr[0],arr[1],arr[2]);
	auto ANS=go(0,0);
	pp(ANS.se);
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


