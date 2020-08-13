
// Problem : C. Barcode
// Contest : Codeforces - Codeforces Round #139 (Div. 2)
// URL : https://codeforces.com/problemset/problem/225/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define plii pair< int,int >
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
int n,m,l,r;
int black[1001],white[1001];
int dp[1001][1001][2];
int go(int pos,int thick,bool flag)
{
	if(pos==m)
	{
		if((thick>=l && thick<=r )|| thick==0)return 0;
		return INT_MAX;	
	}
	if(dp[pos][thick][flag]!=-1)return dp[pos][thick][flag];
	if(pos==0)
		return dp[pos][thick][flag]=min(black[0]+go(pos+1,1,false),white[0]+go(pos+1,1,true));
	if(flag)//black -> true
	{
		if(thick==r){
			return dp[pos][thick][flag]=black[pos]+go(pos+1,1,false);
		}
		else if(thick<l)
		{
			return dp[pos][thick][flag]=white[pos]+go(pos+1,thick+1,true);
		}
		return dp[pos][thick][flag]=min(white[pos]+go(pos+1,thick+1,true),
				   black[pos]+go(pos+1,1,false)
		);
	}
	if(thick==r){
		return dp[pos][thick][flag]=white[pos]+go(pos+1,1,true);
	}
	else if(thick<l)
	{
		return dp[pos][thick][flag]=black[pos]+go(pos+1,thick+1,false);
	}
	return dp[pos][thick][flag]=min(black[pos]+go(pos+1,thick+1,false),
			   white[pos]+go(pos+1,1,true)
	);
}
void solve(){
	rd(n,m,l,r);
	FOR(i,n){
		FOR(j,m){
			char c;
			cin>>c;
			if(c=='#') black[j]++;
			else white[j]++;
		}
	}
	pp(go(0,0,false));
	return;	
}


int32_t main() {
	memset(dp,-1,sizeof(dp));
 	fast;
	solve();
    return 0;
}
