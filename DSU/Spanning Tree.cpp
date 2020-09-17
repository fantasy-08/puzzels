
// Problem : E. Spanning Tree
// Contest : Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 2
// URL : https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E
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
	int n,q;
	rd(n,q);
	int par[n+1],size[n+1];
	vector<vector<int>>edg;
	FOR(i,q){
		int u,v,c;
		rd(u,v,c);
		edg.pb({u,v,c});
	}
	sort(all(edg),[](vint a,vint b){
		return a[2]<b[2];
	});
	initialize(par,size,n+1);
	int ans=0;
	for(auto e:edg){
		int u=e[0],v=e[1],w=e[2];
		if(root(par,u)==root(par,v))continue;
		union1(par,size,u,v);
		ans=max(ans,w);
	}
	pp(ans);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
