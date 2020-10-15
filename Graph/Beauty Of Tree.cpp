
// Problem : Beauty of tree
// Contest : Google Coding Competitions - Round D 2020 - Kick Start 2020
// URL : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd
// Memory Limit : 1024 MB
// Time Limit : 20000 ms
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

int dp[5000005][2];

void go(int node,int par,vector<int>&arr,int &dis,bool F,vector<int>adj[])
{
	dp[node][F]=1;
	arr.pb(node);
	for(auto child:adj[node]){
		if(child!=par){
			go(child,node,arr,dis,F,adj);
		}
	}
	arr.pop_back();
	int N=arr.size();
	if(N>=dis){
		dp[arr[N-dis]][F]+=dp[node][F];
	}
}

double solve(){
	int n,a,b;
	rd(n,a,b);
	vector<int>adj[n+1];
	
	for(int i=2;i<=n;i++)
	{
		int t;
		rd(t);
		adj[i].pb(t);
		adj[t].pb(i);
	}
	
	vector<int>arr;
	go(1,-1,arr,a,0,adj);
	go(1,-1,arr,b,1,adj);
	
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(n*(dp[i][0]+dp[i][1])-(dp[i][0]*dp[i][1]));
	}
	ans/=(n*n);
	
	return ans;
}


int32_t main() {
   fast;
	precision(10);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cout<<"Case #"<<i<<" :"<<solve()<<endl;
    }
    
    return 0;
}
