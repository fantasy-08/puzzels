
// Problem : C. Block Towers
// Contest : Codeforces - 8VC Venture Cup 2016 - Elimination Round
// URL : https://codeforces.com/problemset/problem/626/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define plii pair< int,int >
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
	int a,b;
	rd(a,b);
	if(a==0 || b==0){
		pp(max(a*2,b*3));
		return ;
	}
	// int l=0,h=INT_MAX;
	// int ans=INT_MAX;
	// while(l<=h){
		// int i=l+(h-l)/2;
		// if((a<=(i/2))&&(b<=(i/3)) && ((a+b)<=(i/2+i/3-i/6))){
			// ans=a;
			// h=a-1;
		// }
		// else l=a+1;
	// }
	// pp(ans);
	// return ;
	for(int i=1;;i++){
		if((a<=(i/2))&&(b<=(i/3)) && ((a+b)<=(i/2+i/3-i/6))){
			pp(i);
			return ;
		}
	}
	pp(max(a*2,b*3));
		return ;
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
