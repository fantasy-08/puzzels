
// Problem : B. Arpa's weak amphitheater and Mehrdad's valuable Hoses
// Contest : Codeforces - Codeforces Round #383 (Div. 1)
// URL : https://codeforces.com/contest/741/problem/B
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
int par[1001],size[1001];
void initialize( int Arr[ ],int size[], int N)
{
    for(int i = 0;i<N;i++)
	{
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
	    Arr[ i ] = Arr[ Arr[ i ] ] ; 
		i = Arr[ i ]; 
	}
	return i;
}
void union1(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
		Arr[ root_A ] = Arr[root_B];
		size[root_B] += size[root_A];
	}
    else
    {
		Arr[ root_B ] = Arr[root_A];
		size[root_A] += size[root_B];
	}

}
void solve(){
	int n,m,k;
	rd(n,m,k);
	
	initialize(par,size,n+1);
	int weight[n+1];
	int beauty[n+1];
	rep(i,1,n+1)rd(weight[i]);
	rep(i,1,n+1)rd(beauty[i]);
	
	FOR(i,m)
	{
		int u,v;
		rd(u,v);
		union1(par,size,u,v);
	}
	
	map<int,pair<int,int>>Cost;
	map<int,vector<int>>Group;
	int max_pos=0;
	
	for(int i=1;i<=n;i++)
	{
		int parent=root(par,i);
		if(Cost.find(parent)==Cost.end())
		Cost[parent]={beauty[i],weight[i]};	
		else
		Cost[parent].ft+=beauty[i],Cost[parent].se+=weight[i];
		Group[parent].pb(i);
		
	}
	
	for(auto v:Cost)
	{
		if(v.se.se<=k)
			max_pos=max(max_pos,v.se.ft);
	}
	
	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
/*	
	for(auto p:Group){
		cout<<p.ft<<" -> ";
		for(auto val:p.se)cout<<val<<" ";
		cout<<endl; 
	}
*/
	for(int i=0;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=max(dp[i][j],dp[i][j-1]);
			int tot_beauty=0,tot_weight=0;
			for(auto member:Group[j])
			{
				tot_beauty+=beauty[member],tot_weight+=weight[member];
				if(weight[member]>i)continue;
				dp[i][j]=max(dp[i][j],dp[i-weight[member]][j-1]+beauty[member]);
			}
			if(tot_weight<=i)
				dp[i][j]=max(dp[i][j],dp[i-tot_weight][j-1]+tot_beauty);
		}
	}
	pp(max(dp[k][n],max_pos));
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
