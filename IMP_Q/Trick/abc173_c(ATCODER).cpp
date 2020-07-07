
// Problem : C - H and V
// Contest : AtCoder - AtCoder Beginner Contest 173
// URL : https://atcoder.jp/contests/abc173/tasks/abc173_c
// Memory Limit : 1024 MB
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
char arr[7][7];
int m,n,k;
int res=0;
// map<pair<int,int>,bool>chk;
void cal(int r,int c){
	// if(chk.find({r,c})!=chk.end())return ;
	int ans=0;
	FOR(i,n){
		FOR(j,m){
			if(r&(1<<i) || c&(1<<j)) continue;
			if(arr[i][j]=='#')ans++;
		}
	}
	if(ans==k)res++;
	// chk[{r,c}]=true;
}
void go(int r,int c){
	for(int i=0;i<pow(2,n);i++){
		for(int j=0;j<pow(2,m);j++){
			cal(i,j);
		}		
	}		
}
void solve(){
	cin>>n>>m>>k;
	int black=0;
	FOR(i,n){
		FOR(j,m){
			cin>>arr[i][j];
			if(arr[i][j]=='#')black++;
		}
	}
	go(0,0);
	cout<<res;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
