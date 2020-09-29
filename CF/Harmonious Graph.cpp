
// Problem : D. Harmonious Graph
// Contest : Codeforces - Codeforces Round #600 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1253/D
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
void initialize( int Arr[ ],int size[], int N)
{
    for(int i = 0;i<N;i++)
	{
		Arr[ i ] = i ;
		size[i]=1;
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
void union1(int Arr[ ],int size[],int A,int B)
{
     int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(root_A==root_B)return ;
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
	int par[n+1],size[n+1];
	
	initialize(par,size,n+1);
	set<int>s;
	unordered_map<int,int>L,F;
	FOR(i,m){
		int u,v;
		rd(u,v);
		s.insert(u),s.insert(v);
		union1(par,size,u,v);
	}

	for(auto u:s)
	{
		int parent=root(par,u);
		L[parent]=max({u,L[parent]});
		if(F.find(parent)==F.end())F[parent]=u;
		else F[parent]=min({u,F[parent]});
	}
	vector<vector<int>>range;
	for(auto v:L){
		range.pb({F[v.ft],v.se,v.ft});
	}
	sort(all(range),[](vint A,vint B){
		if(A[0]!=B[0])return A[0]<B[0];
		return A[1]<B[1];
	});
	// for(auto v:range)
	// {
		// pp(v[0],v[1],v[2]);
	// }
	int i=0,ans=0;
	while(i<range.size())
	{
		pint R={range[i][0],range[i][1]};
		int P=range[i][2];
		int j=i+1;
		while(j<range.size())
		{
			if(range[j][0]>R.se)break;
			else
			{
				ans++;
				union1(par,size,P,range[j][2]);
				R={min(R.ft,range[j][0]),max(R.se,range[j][1])};
				j++;
			}
		}
		// pp(R.ft,R.se,size[root(par,P)]);
		int Len=abs(R.se-R.ft+1);
		int S=size[root(par,P)];
		ans+=Len-S;
		i=j;		
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
