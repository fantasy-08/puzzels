
// Problem : C. Hard problem
// Contest : Codeforces - Codeforces Round #367 (Div. 2)
// URL : https://codeforces.com/problemset/problem/706/C
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
int n;
vint cost;
vector<string>arr,arrr;
int dp[100005][2];
bool pos=false;
int go(int i,bool isrev){
	if(i==n){
		pos=true;
		return 0;
	}
	if(dp[i][isrev]!=-1)return dp[i][isrev];
	if(i==0){
		return dp[i][isrev]=min(go(i+1,false),go(i+1,true)+cost[0]);
	}
	string X=arr[i] ,X1=arr[i-1];
	string Y=arrr[i],Y1=arrr[i-1];

	if(isrev){
		int temp=1e16;
		if(Y1<=X)temp=min(temp,go(i+1,false));
		if(Y1<=Y)temp=min(temp,go(i+1,true)+cost[i]);	
		return dp[i][isrev]=temp;
	}
	else
	{
		int temp=1e16;
		if(X1<=X)temp=min(temp,go(i+1,false));
		if(X1<=Y)temp=min(go(i+1,true)+cost[i],temp);
		return dp[i][isrev]=temp;
	}
}
void solve(){
	rd(n);
	cost.resize(n);
	arr.resize(n);
	arrr.resize(n);
	FOR(i,n)rd(cost[i]);
	FOR(i,n)rd(arr[i]);
	FOR(i,n){
		string s=arr[i];
		reverse(all(s));
		arrr[i]=s;
	}	
	int ans=(go(0,false));
	if(!pos)	pp(-1);
	else 		pp(ans);
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
