
// Problem : E. Two Platforms
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

void solve(){
	int n,k;
	rd(n,k);
	vint x(n),y(n);
	FOR(i,n)rd(x[i]);
	FOR(i,n)rd(y[i]);
	sort(all(x));
	vector<int>ans(n,0);
	// ans[n-1]=1;
	for(int i=0;i<=n-1;i++){
		int pos=x[i];
		int extreme=pos+k;
		auto Y=upper_bound(all(x),extreme);
		if(Y==x.end())ans[i]=n-i;
		else ans[i]=(Y-x.begin())-i;
	}
	// for(auto v:ans)cerr<<v<<" ";
	// cerr<<endl;
	int val=0;
	vector<int>pre(n);
	pre[n-1]=ans[n-1];
	for(int i=n-2;i>=0;i--)pre[i]=max(pre[i+1],ans[i]);
	for(int i=0;i<n;i++){
		int curr=ans[i];
		int nxt=i+curr;
		if(nxt<n) nxt=pre[nxt];
		else 	  nxt=0;
		val=max(val,nxt+curr);
	}
	pp(val);
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
