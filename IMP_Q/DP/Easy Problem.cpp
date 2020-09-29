
// Problem : D. Easy Problem
// Contest : Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1096/D
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
string s;
vint score;
int dp[100001][4];
int go(int pos,int w)
{
	if(pos==n)return 0;
	if(dp[pos][w]!=-1)return dp[pos][w];
	if(s[pos]=='h')
	{
		if(w==0)return dp[pos][w]=min(go(pos+1,1),score[pos]+go(pos+1,0));
		return dp[pos][w]=go(pos+1,w);
	}
	else if(s[pos]=='a'){
		if(w==1)return dp[pos][w]= min(go(pos+1,2),score[pos]+go(pos+1,1));
		return dp[pos][w]=go(pos+1,w);
	}
	else if(s[pos]=='r'){
		if(w==2)return dp[pos][w]=min(go(pos+1,3),score[pos]+go(pos+1,2));
		return dp[pos][w]=go(pos+1,w);
	}
	else if(s[pos]=='d'){
		if(w==3)return dp[pos][w]=score[pos]+go(pos+1,w);
		return dp[pos][w]=go(pos+1,w);
	}
	return dp[pos][w]=go(pos+1,w);
}
void solve(){
	rd(n);
	rd(s);
	score.resize(n);
	for(int i=0;i<n;i++){
		rd(score[i]);
		dp[i][0]=-1,dp[i][1]=-1,dp[i][2]=-1,dp[i][3]=-1;
	}
	pp(go(0,0));
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}

