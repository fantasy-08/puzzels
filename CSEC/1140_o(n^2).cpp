
// Problem : Projects
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1140
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
int n;
vector<pair<int,pair<int,int>>>arr;
map<pair<int,int>,int>dp;
int go(int i,int j){
	if(i==n)return 0;
	if(j==-1){
		return max(arr[i].se.se+go(i+1,i),go(i+1,j));
	}
	else{
		if(dp.find({i,j})!=dp.end())return dp[{i,j}];
		if(arr[i].ft>=arr[j].se.ft){
			return dp[{i,j}]=max(arr[i].se.se+go(i+1,i),go(i+1,j));
		}
		return dp[{i,j}]=go(i+1,j);
	}
}


void solve(){
	cin>>n;
	FOR(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		arr.pb({a,{b,c}});
	}
	cout<<go(0,-1);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
