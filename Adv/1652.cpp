
// Problem : Forest Queries
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1652
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
	int n,m;
	cin>>n>>m;
	int q=m;
	m=n;
	int arr[n][m];
	memset(arr,0,sizeof(arr));	
	FOR(i,n)
	{
		FOR(j,m)
		{
			char t;
			cin>>t;
			if(t=='.') arr[i][j]=0;
			else       arr[i][j]=1;
		}
	}
	rep(j,1,m) arr[0][j]+=arr[0][j-1];
	rep(i,1,n) arr[i][0]+=arr[i-1][0];
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
		}
	}
	FOR(i,n){
		FOR(j,m)cerr<<arr[i][j]<<" ";
		cerr<<endl;
	}
	
	while(q--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--,x2--,y1--,y2--;
		int b=arr[x2][y2];
		int l;
		if(x1!=0) l=arr[x1-1][y2];
		else l=0;
		int r;
		if(y1!=0) r=arr[x2][y1-1];
		else r=0;
		int k;
		if(x1!=0 && y1!=0) k=arr[x1-1][y1-1];
		else 			   k=0;
		cerr<<b<<" "<<l<<" "<<r<<" "<<k<<" "<<endl;
		cout<<b-(k+r+l)<<endl;
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

