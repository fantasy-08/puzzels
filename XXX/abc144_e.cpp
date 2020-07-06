
// Problem : E - Gluttony
// Contest : AtCoder - AtCoder Beginner Contest 144
// URL : https://atcoder.jp/contests/abc144/tasks/abc144_e
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

bool go(vector<pair<int,int>>arr,int mid,int k){
	for(int i=0;i<arr.size();i++){
		if(arr[i].ft*arr[i].se<=mid)continue;
		else{
			int rem=mid/arr[i].se;
			int to_sub=arr[i].ft-rem;
			if(k>=to_sub)k-=to_sub;
			else return false;
		}
	}
	return true;
}


void solve(){
	int n,k;
	rd(n,k);
	vlli arr(n),p(n);
	int sum=0;
	FOR(i,n){
		cin>>arr[i];
		sum+=arr[i];
	}
	
	FOR(i,n){
		rd(p[i]);
	}
	
	if(sum<=k){
		pp(0);
		return ;
	}
	
	sort(all(arr));

	sort(all(p),greater<int>());
	int l=0,h=arr[n-1]*p[n-1];
	vector<pair<int,int>>v;
	FOR(i,n){
		v.pb({arr[i],p[i]});
	}
	int ans=h;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		// error(mid);
		if(go(v,mid,k)){
			ans=min(ans,mid);
			h=mid-1;
		}
		else l=mid+1;
	}
	pp(ans);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
