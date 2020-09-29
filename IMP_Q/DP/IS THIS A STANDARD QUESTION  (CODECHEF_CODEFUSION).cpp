
// Problem : IS THIS A STANDARD QUESTION 
// Contest : CodeChef - CodeFusion 20.9
// URL : https://www.codechef.com/CFUS2020/problems/CFS2003
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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
// int arr[100001];
// int dp[100001];
map<pint,int>dp2;
int n;
unordered_map<int,int>portal;
/*int go(int pos)
{
	if(pos==n)return 0;
	if(pos>n)return n+2;
	if(dp[pos]!=-1)return dp[pos];
	int ans=min(1+go(pos+1),1+go(pos+2));
	if(portal.find(pos)!=portal.end())ans=min(ans,1+go(portal[pos]));
	return dp[pos]=ans;
}
int ways(int pos,int step)
{
	if(pos==n){
		if(step==0)return 1;
		return 0;
	}
	if(pos>n)return 0;
	if(step<=0)return 0;
	if(dp2.find({pos,step})!=dp2.end())return dp2[{pos,step}];
	int ans=ways(pos+1,step-1)+ways(pos+2,step-1);
	if(portal.find(pos)!=portal.end())ans+=ways(portal[pos],step-1);
	return dp2[{pos,step}]=ans;
}*/
void solve(){
	int k;
	rd(n,k);
	vint v(k);
	for(int&V:v)rd(V);
	sort(all(v));
	rep(i,1,k){
		portal[v[i]]=v[i-1];
	}
	vector<map<int,int>>dp(n+1,map<int,int>());
	dp[1][0]=0;
	dp[2][1]=1;
	dp[3][2]=1;
	dp[3][1]=1;
	for(int i=4;i<=n;i++)
	{
		int M=(*(dp[i-1].begin())).ft;
		dp[i][1+M]+=(*(dp[i-1].begin())).se;
		int M2=(*(dp[i-2].begin())).ft;
		dp[i][1+M2]+=(*(dp[i-2].begin())).se;
		if(portal.find(i)!=portal.end()){
			int index=portal[i];
			int M3=(*(dp[index].begin())).ft;
			dp[i][1+M3]+=(*(dp[index].begin())).se;
		}
	}
	auto Ans=*dp[n].begin();
	pp(Ans.se,Ans.ft);
	return;	
}


int32_t main() {
    fint{
    	// memset(dp,-1,sizeof(dp));
    	portal.clear();
    	// dp2.clear();
    	solve();
    }
    return 0;
}
