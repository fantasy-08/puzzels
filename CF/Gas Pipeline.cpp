
// Problem : C. Gas Pipeline
// Contest : Codeforces - Educational Codeforces Round 71 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1207/C
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
int n,a,b;
string s;
int go(int pos,bool big){
	// if(pos==n)return 0;
	if(pos==n){
		if(big)return  2*b;
		return b;
	}
	if(pos==0){
		if(s[pos]=='1'){
			return min(2*b+a+go(pos+1,true),2*b+2*a+go(pos+1,false));
		}
		return min({2*b+a+go(pos+1,true),b+a+go(pos+1,false),2*b+2*a+go(pos+1,false),b+2*a+go(pos+1,true)});
	}
	if(s[pos]=='1'){
		if(big){
			return min(2*b+a+go(pos+1,true),2*b+2*a+go(pos+1,false));
		}
		return 1e10;
	}
	if(!big){
		return min(2*a+b+go(pos+1,true),b+a+go(pos+1,false));
	}
	return min(2*b+a+go(pos+1,true),2*b+2*a+go(pos+1,false));
}
void solve(){
	rd(n,a,b,s);
	// s=s+'0';
	pp(go(0,false));
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
