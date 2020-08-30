
// Problem : B. Born This Way
// Contest : Codeforces - Codeforces Global Round 3
// URL : https://codeforces.com/problemset/problem/1148/B
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

void solve(){
	int n,m,ta,tb,k;
	rd(n,m,ta,tb,k);
	vint a(n),b(m);
	FOR(i,n)rd(a[i]),a[i]+=ta;
	FOR(i,m)rd(b[i]),b[i]+=tb;
	if(k>=n || k>=m){
		pp(-1);
		return ;
	}	
	// int l=0,h=k;
	int ans=0;
	for(int mid=0;mid<=k;mid++){
		// int mid=l+(h-l)/2;
		int rem=k-mid;
		int eA=a[mid];
		auto ind=upper_bound(all(b),eA);
		if(ind==b.end()){
			pp(-1);
			return;
		}
		int I=ind-b.begin();
		I+=rem;
		if(I>=m){
			pp(-1);
			return ;
		}
		if(ans<=b[I]){
			ans=b[I];
			// l=mid+1;
		}
		// else h=mid-1;
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
