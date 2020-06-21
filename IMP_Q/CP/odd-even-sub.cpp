
// Problem : D. Odd-Even Subsequence
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/D
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
int n,k;
int arr[200005];
bool even_pos(int mid)
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(x%2==0){
			if(arr[i]<=mid)x++;
		}
		else x++;
	}
	return x>=k;
}

bool odd_pos(int mid){
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(x%2){
			if(arr[i]<=mid)x++;
		}
		else x++;
	}
	return x>=k;
}

void solve(){
	
	cin>>n>>k;
	FOR(i,n)cin>>arr[i];
	int ans=1e9;
	int l=1,h=1e9;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		if(even_pos(mid) || odd_pos(mid)){
			ans=min(ans,mid);
			h=mid-1;
		}
		else l=mid+1;
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
