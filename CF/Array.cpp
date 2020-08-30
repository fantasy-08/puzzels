
// Problem : B. Array
// Contest : Codeforces - Codeforces Round #138 (Div. 2)
// URL : https://codeforces.com/problemset/problem/224/B
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

void solve(){
	int n,k;
	rd(n,k);
	vint a(n);
	sint s;
	FOR(i,n){
		rd(a[i]);
		s.insert(a[i]);
	}	
	if(s.size()<k)pp(-1,-1);
	else{
		int ans=n;
		int l=1,r=n;
		int i=0,j=0;
		int count[100005]={0},dis=0;
		while(i<=j && j<n){
			count[a[j]]++;
			if(count[a[j]]==1)dis++;
			if(dis>=k){
				while(dis>=k){
					int len=j-i+1;
					if(len<ans){
						l=i+1,r=j+1,ans=j-i+1;
					}
					count[a[i++]]--;
					if(count[a[i-1]]==0)dis--;
				}
			}
			j++;
		}
		pp(l,r);
	}
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
