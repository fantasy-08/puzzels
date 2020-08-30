
// Problem : D. Vasya and Arrays
// Contest : Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1036/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
	int sum=0;
	int n;rd(n);
	vint a(n);
	FOR(i,n)rd(a[i]),sum+=a[i];
	int m;rd(m);
	vint b(m);
	FOR(i,m)rd(b[i]),sum-=b[i];
	int i=0,j=0,count=0;
	// if(sum!=0){
		// pp(-1);
		// return ;
	// }
	while(i<n && j<m){
		if(a[i]==b[j])i++,j++;
		else{
			int A=a[i],B=b[j];
			while(i<n && j<m && A!=B){
				if(A<B)A+=a[++i];
				else   B+=b[++j];
			}
			if(A!=B){
				pp(-1);
				return ;
			}
			i++,j++;
		}
		count++;
	}
	// pp(count);
	if(i!=n || j!=m){
		pp(-1);
	}
	else
	pp(count);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
// 49
// 18 1 7 2 1 1 50 22 8 2 2 1 30 2 46 10 1 4 5 18 25 21 38 11 2 15 29 8 7 2 45 12 14 16 16 23 11 1 1 4 48 18 3 1 1 23 4 10 7
// 50
// 5 25 34 22 19 4 4 2 40 52 1 4 1 3 47 9 4 1 8 47 4 5 1 1 9 22 9 2 2 1 1 48 7 2 8 16 4 2 41 12 3 30 21 10 2 2 5 1 31 13