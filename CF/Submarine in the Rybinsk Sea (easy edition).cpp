
// Problem : D1. Submarine in the Rybinsk Sea (easy edition)
// Contest : Codeforces - Codeforces Round #574 (Div. 2)
// URL : https://codeforces.com/contest/1195/problem/D1
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
#define MOD 998244353 
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int val[40]={0};
void solve(){
	int n;
	rd(n);
	int arr[2][n];
	FOR(i,n){
		string s;
		rd(s);
		reverse(all(s));
		int Power1=1,Power2=0;
		int value1=0,value2=0;
		FOR(j,s.size()){
			value1=((value1)%MOD+((s[j]-'0')*val[Power1])%MOD)%MOD;
			value2=((value2)%MOD+((s[j]-'0')*val[Power2])%MOD)%MOD;
			// cerr<<j<<" "<<value1<<" "<<Power1<<" "<<val[Power1]<<endl;
			Power1+=2,Power2+=2;
		}
		arr[0][i]=value1%MOD;
		arr[1][i]=value2%MOD;
		// cout<<arr[0][i]<<" "<<arr[1][i]<<endl;
	}
	int ans=0;
	FOR(i,n){
		int X=(arr[0][i]*(n%MOD))%MOD;
		int Y=(arr[1][i]*(n%MOD))%MOD;
		ans=(ans%MOD+X+Y)%MOD;
	}
	pp(ans%MOD);
	return;	
}
int32_t main() {
    // fint{
	int Mul=1;
	FOR(i,40){
		val[i]=Mul%MOD;
		Mul=((Mul%MOD)*10)%MOD;
	}
	// FOR(i,40)error(val[i]);
	fast;
	solve();
    // }
    return 0;
}

