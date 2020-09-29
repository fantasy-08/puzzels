
// Problem : A. Garland
// Contest : Codeforces - Codeforces Round #612 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1286/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vint vector<int>
#define sint set<int>
#define mint map<int,int>
#define pint pair< int,int >
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
int n,o,e;
int arr[101];
int dp[101][52][52][2];
int go(int pos,int O,int E,int prev){//(true Odd) (false Even)
	if(O<0 || E<0)return INT_MAX;
	if(pos>=n){
		return 0;
	}
	if(dp[pos][O][E][prev]!=-1)return dp[pos][O][E][prev];
	if(pos==0){
		if(arr[pos]==0)return dp[pos][O][E][prev]=min(go(pos+1,O-1,E,1),go(pos+1,O,E-1,0));
		if(arr[pos]&1 )return dp[pos][O][E][prev]=go(pos+1,O,E,1);
		return dp[pos][O][E][prev]=go(pos+1,O,E,0);
	}
	int ans=INT_MAX;
	int val=arr[pos];
	if(val==0){
		if(O>0){
			int temp_ans=0;
			if(prev==0)temp_ans=1;
			temp_ans+=go(pos+1,O-1,E,1);
			ans=min(ans,temp_ans);			
		}
		if(E){
			int temp_ans=0;
			if(prev)temp_ans=1;
			temp_ans+=go(pos+1,O,E-1,0);
			ans=min(ans,temp_ans);
		}
		return dp[pos][O][E][prev]=ans;
	}
	ans=0;
	if	   (arr[pos]%2==0 && prev==1)ans=1;
	else if(arr[pos]%2==1 && prev==0)ans=1;
	bool temp_prev;
	if(arr[pos]%2==0)temp_prev=0;
	else temp_prev=1;
	return dp[pos][O][E][prev]=(ans+go(pos+1,O,E,temp_prev));
}
void solve(){
	rd(n);
	FOR(i,n){
		rd(arr[i]);
		if(arr[i]==0)continue;		
		if(arr[i]&1)o++;
		else e++;
	}
	int temp_o=n/2;
	int temp_e=n/2;
	if(n&1)temp_o++;
	o=temp_o-o;
	e=temp_e-e;
/*
	FOR(i,n+1){
		FOR(j,o+1){
			FOR(k,e+1){
				dp[i][j][k][0]=-19;
				dp[i][j][k][1]=-19;
			}
		}
	}
*/
	pp(go(0,o,e,0))	;
	return;	
}


int32_t main() {
    // fint{
    	memset(dp,-1,sizeof(dp));
    	fast;
    	solve();
    // }
    return 0;
}
