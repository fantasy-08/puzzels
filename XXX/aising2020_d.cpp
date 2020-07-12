
// Problem : D - Anything Goes to Zero
// Contest : AtCoder - AIsing Programming Contest 2020
// URL : https://atcoder.jp/contests/aising2020/tasks/aising2020_d
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

int power(int a,int b,int m)
{
	if(b==1)return a%m;
	if(b==0)return 1%m;
	if(b&1)return ((a%m)*(power(a,b-1,m)%m))%m;
	return ((power(a,b/2,m)%m)*(power(a,b/2,m)%m))%m;
}
int cal(int x){
	if(x==0)return 0;
	int moves=0;
	while(x!=0){
		x=x%(__builtin_popcount(x));
		moves++;
	}
	return moves;
}
void solve(){
	int n;
	rd(n);
	string s;
	rd(s);
	int num=0,pop=0;
	string k=s;
	reverse(all(k));
	// error(k);
	FOR(i,n)pop+=(s[i]-'0');
	int pp=pop+1,pn=pop-1;
	int xp=0,xn=0;
	FOR(i,n){
		// error(i);
		if(k[i]-'0'){
			if(pn>0)
			xp+=power(2,i,pp)%pp;
			if(pp>0)
			xn+=power(2,i,pn)%pn;
			xp%=pp;
			xn%=pn;
		}
		// error(i);
	}
	// error(n);
	// Error(xp,xn);
	FOR(i,n){
		// error(i);
		int Poo=n-i-1;
		if(pop==0){
			cout<<1<<endl;
			continue;
		}
		if(s[i]-'0'){
			if(pop<=2){
				cout<<(1)<<endl;
				continue;
			}
			int ans=(xn-power(2,Poo,pn))%pn;
			ans=(pn+ans)%pn;
			// cout<<ans<<"-";
			cout<<(1+cal(ans))<<endl;
		}
		else{
			int ans=(xp%pp+power(2,Poo,pp)%pp)%pp;
			// cout<<ans<<"-";
			cout<<(1)+cal(ans)<<endl;
		}
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
