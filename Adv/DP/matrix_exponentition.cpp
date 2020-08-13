
// Problem : B. String Mood
// Contest : Codeforces - Matrix Exponentiation
// URL : https://codeforces.com/gym/102644/problem/B
// Memory Limit : 256 MB
// Time Limit : 250 ms
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
vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b)
{
	vector<vector<int>> res(2,vector<int>(2,0));
	FOR(i,2){
		FOR(j,2){
			FOR(k,2){
				res[i][k]=(res[i][k]%MOD+(a[i][j]%MOD)*(b[j][k]%MOD))%MOD;
			}
		}
	}
	return res;
}
vector<vector<int>> expo(vector<vector<int>> a,int n){
	vector<vector<int>> res={{1,0},{0,1}};
	while(n>0){
		if(n&1){
			res=mul(res,a);
		}
		n/=2;
		a=mul(a,a);
	}
	return res;
}
void solve(){
	int n;
	rd(n);
	vector<vector<int>>a={{19,7},{6,20}}	;
	vector<vector<int>>ans=expo(a,n);
	pp(ans[0][0]%MOD);
	return;	
}


int32_t main() {
	fast;
	solve();
    return 0;
}
