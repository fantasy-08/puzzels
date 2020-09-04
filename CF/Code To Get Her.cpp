
// Problem : Code To Get Her
// Contest : CodeChef - Code Mates x1
// URL : https://www.codechef.com/COMX2020/problems/CMX1P03
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
#define MOD 998244353
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int mod = 998244353;
int fact[100000+10];
int power(int a, int n, int mod) {
	int res = 1;
	while(n > 0) {
		if(n&1) {
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		n = n/2;
	}
	return res;
}
int ncr(int n, int r) {
	if(n == 0 or r==0) return 1; 
	return (fact[n]* power((fact[r]*fact[n-r])%mod,mod-2,mod))%mod;
}
void solve(){
	string s;
	rd(s);
	mint freq;
	for(auto c:s)
	{
		freq[c-'a']++;
	}
	int names;
	rd(names);
	vint scr;
	// rep(i,0,26){char C='a'+i;Error(C,freq[i]);}
	string Name="";
	int max_scr=0;
	while(names--)
	{
		string name;
		rd(name);
		mint temp;
		for(auto c:name)
		{
			temp[c-'a']++;
		}
		bool pos=true;
		rep(i,0,26)
		{
			if(temp[i]>freq[i])
			{
				scr.pb(0);
				pos=false;
				break;
			}
		}		
		if(pos)
		{
			int score=1;
			rep(i,0,26)
			{
				if(temp[i]!=0)
				{
					score*=(ncr(freq[i],temp[i]))%MOD;
					score%=MOD;
				}
			}
			if(score>max_scr)
			{
				Name=(name);
				max_scr=score;
			}
			scr.pb(score);
		}
	}
	for(auto v:scr)pp(v);
	if(max_scr==0)pp("No Research This Month");
	else pp(Name);
	return;	
}


int32_t main() {
	fact[0] = 1;
	for(int i=1; i<=100000; i++) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
	}
    fint{
    	solve();
    }
    return 0;
}
