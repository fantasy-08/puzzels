
// Problem : Counting Divisors
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1713
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
map<int,map<int,int>>D;
int maxN=1000001;
vector<int>primes;
bool chk[1000001];
void buid()
{
	rep(i,2,(int)sqrt(1000001))
	{
		if(chk[i]==false)
		{
			primes.pb(i);
			for(int j=i*i;j<maxN;j+=i)
				chk[i]=true;
		}
	}
	error(maxN);
}
bool Find(int n)
{
	for(auto p:primes)
	{
		int k=p*p;
		if(k>n)return false;
		if(k==n)return true;
	}
	return false;
}
void solve(){
	int n;
	cin>>n;
	int ans=1;
	for(auto p:primes)
	{
		if(p*p*p>n)break;
		int count=1;
		while(n%p==0)
		{
			n/=p;
			count++;
		}
		ans*=count;
	}
	if(binary_search(all(primes),n))
	{
		ans*=2;
	}
	else if(Find(n))
	{
		ans*=3;
	}
	else
		ans*=4;
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    buid();
    fint{
    	
    	fint
    	solve();
    }
    return 0;
}
