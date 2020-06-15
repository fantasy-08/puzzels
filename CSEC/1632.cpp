
// Problem : Movie Festival II
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1632
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

void solve(){
	int n,k;
	cin>>n>>k;
	vlli K(k,0);
	vector<pair<int,int>>v;
	FOR(i,n){
		int a,b;
		cin>>a>>b;
		v.pb({a,b});
	}	
	sort(all(v),[](pair<int,int>X,pair<int,int>Y){
		if(X.se!=Y.se)
		return X.se<Y.se;
		return X.ft>Y.ft;
	});
	int count=0;
	for(auto p:v){
		int S=p.ft;
		FOR(i,k){
			if(K[i]<=S){
				count++;
				K[i]=p.se;
				break;
			}
		}	
	}
	cout<<count;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
