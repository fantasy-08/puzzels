
// Problem : B. Mahmoud and Ehab and the message
// Contest : Codeforces - Codeforces Round #473 (Div. 2)
// URL : https://codeforces.com/problemset/problem/959/B
// Memory Limit : 256 MB
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
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
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
	int n,q,k;
	cin>>n>>k>>q;
	map<string,int>m;
	rep(i,1,n+1){
		string temp;
		cin>>temp;
		m[temp]=i;
	}	
	mlli cost;
	rep(i,1,n+1){
		int t;
		cin>>t;
		cost[i]=t;
	}
	mlli group,which;
	rep(i,1,k+1){
		int time;
		cin>>time;
		while(time--){
			int t;
			cin>>t;
			which[t]=i;
			if(group.find(i)==group.end()){
				group[i]=cost[t];
			}
			else{
				group[i]=min(group[i],cost[t]);
			}
		}
	}
	int ans=0;
	FOR(i,q){
		string s;
		cin>>s;
		int ind=m[s];
		// Error(s,ind);
		ans+=group[which[ind]];		
	}
	cout<<ans;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
