
// Problem : C - XYZ Triplets
// Contest : AtCoder - AIsing Programming Contest 2020
// URL : https://atcoder.jp/contests/aising2020/tasks/aising2020_c
// Memory Limit : 1024 MB
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
int cal(int x,int y,int z)
{
	return x*x+y*y+z*z+z*y+x*y+z*x;
}
mlli ans;
void init()
{
	for(int i=1;i<100;i++){
		for(int j=1;j<100;j++){
			for(int k=1;k<100;k++){
				int temp=cal(i,j,k);
				if(temp>10000)break;
				else ans[temp]++;
			}
		}
	}
}
void solve(){
	int  n;
	rd(n);
	rep(i,1,n+1){
		pp(ans[i]);
	}
	return;	
}


int32_t main() {
    // fint{
    	init();
    	fast;
    	solve();
    // }
    return 0;
}
