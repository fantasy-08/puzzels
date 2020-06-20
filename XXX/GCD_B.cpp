
// Problem : B. GCD Compression
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/B
// Memory Limit : 256 MB
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
#define present(container, element) (container.find(element)!=container.end())
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
vlli prime;
void build()
{
	vector<bool>a(1001,1);
	for(int i=2;i<=sqrt(1001);i++)
	{
		if(a[i]==true)
		{
			// prime.pb(i);
			for(int j=i*i;j<1001;j+=i)
			{
				a[j]=false;
			}
		}
	}
	rep(i,2,1001)
	if(a[i]==true)prime.pb(i);
}

void solve(){
	int n;
	cin>>n;
	int arr[2*n];
	FOR(i,2*n)
	{
		cin>>arr[i];
	}
	vector<pair<int,int>>ans;
	vector<bool>vis;
	for(auto p:prime)
	{
		vis.clear();
		vis.resize(2*n,true);
		int count=0;
		ans.clear();
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=i+1;j<2*n;j++)
			{
				if(vis[i] && vis[j] && (arr[i]+arr[j])%p==0)
				{
					vis[i]=0;
					vis[j]=0;
					count++;
					ans.pb({i+1,j+1});
				}
			}
		}
		if(count>=n-1)
		{
			FOR(I,n-1)
			cout<<ans[I].ft<<" "<<ans[I].se<<endl;
			return;
		}
		
	}
	return;	
}


int32_t main() {
	build();
    fint{
    	solve();
    }
    return 0;
}
