
// Problem : D2. Remove the Substring (hard version)
// Contest : Codeforces - Codeforces Round #579 (Div. 3)
// URL : https://codeforces.com/contest/1203/problem/D2
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
string a,b;
map<vector<int>,pair<int,int>>dp;
pair<int,int> go(int i,int j,int prev)
{
	if(j==b.size())
	{
		return {true,max(a.size()-i,i-prev-1)};
	}
	if(i==a.size())return {false,0};
	if(dp.find({i,j,prev})!=dp.end())return dp[{i,j,prev}];
	if(a[i]==b[j])
	{
		if(j==0)
		{
			auto A=go(i+1,j+1,i);
			int ans=0;
			bool pos=false;
			if(A.ft==true)
				ans=max(A.se,i),pos=true;
			A=go(i+1,j,i);
			if(A.ft)ans=max(ans,A.se),pos=true;
			return dp[{i,j,prev}]={pos,ans};
		}
		auto A=go(i+1,j+1,i);
		int ans=0;
		bool pos=false;
		if(A.ft==true)
			ans=max(A.se,i-prev-1),pos=true;
		A=go(i+1,j,prev);
		if(A.ft)
			ans=max(ans,A.se),pos=true;
		return dp[{i,j,prev}]={pos,ans};
	}
	return dp[{i,j,prev}]=go(i+1,j,prev);
}
void solve(){
	rd(a,b);	
	int rd[b.size()];
	for(int i=b.size()-1;i>=0;i--){
		int pos=a.size()-1;
		if(i+1<(b.size()))pos=rd[i+1]-1;
		while(a[pos]!=b[i])pos--;
		rd[i]=pos;
	}
	int ans=0;
	int pos=0;
	for(int i=0;i<a.size();i++)
	{
		int rpos=a.size()-1;
		if(pos<b.size())rpos=rd[pos]-1;
		ans=max(ans,rpos-i+1);
		if(pos<b.size() && b[pos]==a[i])pos++;
	
	}
	pp(ans);
	return;	
	
}


int32_t main() {
    // fint{
    	fast;
    	// memset(dp,-1,sizeof(dp));
    	solve();
    // }
    return 0;
}
