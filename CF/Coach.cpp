
// Problem : B. Coach
// Contest : Codeforces - Codeforces Round #181 (Div. 2)
// URL : https://codeforces.com/problemset/problem/300/B
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
int N=50;
int par[50],size[50001];
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
	int n,m;
	rd(n,m);
	FOR(i,m)
	{
		int u,v;
		rd(u,v);
		union1(par,size,u,v);
	}
	map<int,vint>papa;
	map<int,bool>Par;
	rep(i,1,n+1)
	{
		int P=root(par,i);
		if(P==i)Par[i]=true;
		else papa[P].pb(i);
	}
	// for(auto v:Par)pp(v.ft);
	vector<vint>ans;
	for(auto v:papa)
	{
		if(v.se.size()>2)
		{
			pp(-1);
			return ;
		}
		else if(v.se.size()==2)
		{
			ans.pb({v.ft,v.se[0],v.se[1]});
			Par[v.ft]=false;
		}
		else if(v.se.size()==1)Par[v.ft]=false;
	}
	for(auto v:papa)
	{
		if(v.se.size()==1)
		{
			int val=-1;
			for(auto X:Par)
			{
				if(X.se)
				{
					Par[X.ft]=false;
					val=X.ft;
					break;
				}
			}
			if(val==-1){
				pp(-1);
				return ;
			}
			ans.pb({val,v.se[0],v.ft});
		}
	}
	for(auto X:Par)
	{
		if(X.se)
		{
			Par[X.ft]=false;
			int v1=-1,v2=-1;
			for(auto M:Par)
			{
				if(M.se)
				{
					v1=M.ft;
					Par[v1]=false;
					break;
				}
			}
			for(auto M:Par)
			{
				if(M.se)
				{
					v2=M.ft;
					Par[v2]=false;
					break;
				}
			}
			if(v1==-1 || v2==-1)
			{
				pp(-1);
				return;
			}
			ans.pb({X.ft,v1,v2});
		}
	}
	for(auto v:ans)
	{
		for(auto X:v)
		{
			cout<<X<<" ";
		}
		pp("");
	}
	return;	
}


int32_t main() {
    // fint{
    	initialize(par,size,N);
    	fast;
    	solve();
    // }
    return 0;
}
