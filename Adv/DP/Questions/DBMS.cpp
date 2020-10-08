
// Problem : DBMS Assignment
// Contest : CodeChef - TECHWEED
// URL : https://www.codechef.com/TEWE2020/problems/DBAS
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
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
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
void initialize( int Arr[ ],int size[], int N)
{
    for(int i = 0;i<N;i++)
	{
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}

int root(int pa[],int i){
    if(pa[i]==i)return i;
    return pa[i]=root(pa,pa[i]);
}     
void union1(int pa[],int size[],int A,int B){
    int a=root(pa,A);
    int b=root(pa,B);
    if(b>=a)pa[b]=a;
    else pa[a]=b;
}   


int dp[1001][1001];

void solve(){
	int n,q;
	rd(n,q);
	int par[n+1],size[n+1];
	initialize(par,size,n+1);
	while(q--)
	{
		int l,r,k;
		rd(l,r,k);
		if(k==0)continue;
		for(int i=0;i<k;i++){
			for(int j=l+i;j<=r;j+=k)union1(par,size,i+l,j);
		}
	}
	vector<int>sz(n+1,0);
	rep(i,1,n+1)
	{
		sz[root(par,i)]++;
	}
	vector<int>a;
	int tot=0;
	rep(i,1,n+1)
	{
		a.pb(sz[i]);
		tot+=sz[i];
	}
	memset(dp,-1,sizeof(dp));
	function<int(int,int)>go=[&](int pos,int DB)
	{
		if(pos==a.size())return abs(DB-(tot-DB));
		if(dp[pos][DB]!=-1)return dp[pos][DB];
		return dp[pos][DB]=min(go(pos+1,DB+a[pos]),go(pos+1,DB));
	};
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
