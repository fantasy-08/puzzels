
// Problem : Washing Windows
// Contest : CodeChef - November Lunchtime 2019 Division 1
// URL : https://www.codechef.com/LTIME78A/problems/APARTS
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
lli arr[1001][1001],n,m;
void goD(lli i,lli j,lli m){
	if(m==0){
		arr[i+1][j]=max(arr[i+1][j],arr[i][j]);
	}
	else if(m==1){
		arr[i-1][j-1]=max(arr[i-1][j-1],arr[i][j]);
	}
	else if(m==2){
		arr[i+1][j+1]=max(arr[i+1][j+1],arr[i][j]);
	}
	return ;
}
void loo(lli i,lli j){
	if(i+1<n){
		//i-1,j
		goD(i,j,0);
	}
	if(i-1>=0 && j-1>=0){
		goD(i,j,1);	
	}
	if(i+1<n && j+1<m){
		goD(i,j,1);
	}
	loo(i+1,j);
	loo(i-1,j-1);
	loo(i+1,j+1);
	return ;
}
void solve(){
	// cout<<"START\n";
	cin>>n>>m;
	// cout<<"VAL TAKEN\n";
	FOR(i,n)
		FOR(j,m)
			cin>>arr[i][j];
	// cout<<"INPUT TAKEN\n";
	FOR(i,n){error(i);loo(0,i);}
	FOR(i,n) {FOR(j,m) cout<<arr[i][j]<<" "; cout<<endl;}	
	return ;
}


int32_t main() {
	// cout<<"INT1\n";
    test{
    	// cout<<"IN\n";
    	solve();
    }
    return 0;
}
