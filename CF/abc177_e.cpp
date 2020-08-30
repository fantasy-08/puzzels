
// Problem : E - Coprime
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_e
// Memory Limit : 1024 MB
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
#define MAXN 1000001
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int spf[1000001];
unordered_map<int,int>s;
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
bool chk(int x) 
{ 
    set<int> ret; 
    while (x != 1) 
    { 
	    ret.insert(spf[x]);
        x = x / spf[x]; 
    } 
    for(auto v:ret){
    	if(s.find(v)!=s.end())return false;
        s[v]=1; 
    }
    return true; 
    
} 
void solve(){
	// pp(prime.size());
	int n;
	rd(n);
	vint arr(n);
	int tot;
	FOR(i,n){
		rd(arr[i]);
		if(i==0)tot=arr[i];
		else tot=__gcd(tot,arr[i]);
	}
	// set<int>s;
	bool flag=true;
	for(int i=0;i<n;i++){
		// if(!flag)break;
		if(!chk(arr[i])){
			flag=false;
			break;
		}
		// if(!flag)break;
	}
	// for(auto v:s)pp(v);	
	if(flag)pp("pairwise coprime");
	else if(tot==1)pp("setwise coprime");
	else pp("not coprime");
	return;	
}


int32_t main() {
    // fint{
    	sieve();
    	fast;
    	solve();
    // }
    return 0;
}
