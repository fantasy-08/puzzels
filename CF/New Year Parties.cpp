
// Problem : E. New Year Parties
// Contest : Codeforces - Codeforces Round #611 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1283/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int dp[200010][3];
int go(int pos,int prev,int arr[],int n)
{
	if(pos>=n)return 0;
	if(dp[pos][prev]!=-1)return dp[pos][prev];
	if(pos==0)
	{
		return dp[pos][prev]=1+min({go(pos+1,0,arr,n),go(pos+1,1,arr,n),go(pos+1,2,arr,n)});//0->-1 | 1->0 | 2->1
	}	
	if(prev==0)
	{
		int ans=INT_MAX;
		// if(arr[pos]==arr[pos-1]-1)ans=min(ans,go(pos+1,1,arr,n));
		// else ans=min(ans,1+go(pos+1,1,arr,n));
		if(arr[pos]-1==arr[pos-1]-1)ans=min(ans,go(pos+1,0,arr,n));
		else ans=min(ans,1+go(pos+1,0,arr,n));
		ans=min({ans,1+go(pos+1,1,arr,n),1+go(pos+1,2,arr,n)});
		// if(arr[pos]+1==arr[pos-1]-1)ans=min(ans,go(pos+1,2,arr,n));
		// else ans=min(ans,1+go(pos+1,2,arr,n));
		return dp[pos][prev]=ans;
	}
	else if(prev==1){
		int ans=INT_MAX;
		if(arr[pos]==arr[pos-1])ans=min(ans,go(pos+1,1,arr,n));
		else ans=min(ans,1+go(pos+1,1,arr,n));
		if(arr[pos]-1==arr[pos-1])ans=min(ans,go(pos+1,0,arr,n));
		else ans=min(ans,1+go(pos+1,0,arr,n));
		ans=min(ans,1+go(pos+1,2,arr,n));
		return dp[pos][prev]=ans;
	}
	int ans=INT_MAX;
	if(arr[pos]==arr[pos-1]+1)ans=min(ans,go(pos+1,1,arr,n));
	else ans=min(ans,1+go(pos+1,1,arr,n));
	if(arr[pos]-1==arr[pos-1]+1)ans=min(ans,go(pos+1,0,arr,n));
	else ans=min(ans,1+go(pos+1,0,arr,n));
	if(arr[pos]+1==arr[pos-1]+1)ans=min(ans,go(pos+1,2,arr,n));
	else ans=min(ans,1+go(pos+1,2,arr,n));
	return dp[pos][prev]=ans;
}
int go2(int pos,int prev,int arr[],int n)
{
	if(pos>=n)return 0;
	if(dp[pos][prev]!=-1)return dp[pos][prev];
	if(pos==0)
	{
		return dp[pos][prev]=max({1+go2(pos+1,0,arr,n),1+go2(pos+1,1,arr,n),1+go2(pos+1,2,arr,n)});//0->-1 | 1->0 | 2->1
	}	
	if(prev==0)
	{
		int ans=INT_MIN;
		if(arr[pos]-1==arr[pos-1]-1)ans=max(ans,go2(pos+1,0,arr,n));
		else ans=max(ans,1+go2(pos+1,0,arr,n));
		ans=max({ans,1+go2(pos+1,1,arr,n),1+go2(pos+1,2,arr,n)});
		return dp[pos][prev]=ans;
	}
	else if(prev==1){
		int ans=INT_MIN;
		if(arr[pos]==arr[pos-1])ans=max(ans,go2(pos+1,1,arr,n));
		else ans=max(ans,1+go2(pos+1,1,arr,n));
		if(arr[pos]-1==arr[pos-1])ans=max(ans,go2(pos+1,0,arr,n));
		else ans=max(ans,1+go2(pos+1,0,arr,n));
		ans=max(ans,1+go2(pos+1,2,arr,n));
		return dp[pos][prev]=ans;
	}
	int ans=INT_MIN;
	if(arr[pos]==arr[pos-1]+1)ans=max(ans,go2(pos+1,1,arr,n));
	else ans=max(ans,1+go2(pos+1,1,arr,n));
	if(arr[pos]-1==arr[pos-1]+1)ans=max(ans,go2(pos+1,0,arr,n));
	else ans=max(ans,1+go2(pos+1,0,arr,n));
	if(arr[pos]+1==arr[pos-1]+1)ans=max(ans,go2(pos+1,2,arr,n));
	else ans=max(ans,1+go2(pos+1,2,arr,n));
	return dp[pos][prev]=ans;
}
vector<int>cnt;
int solvemax(){
	int res = 0;
	int dist = 2;
	bool right = false;
	int n=cnt.size();
	FOR(i, n){
		if (!cnt[i]){
			++dist;
			continue;
		}
		int j = i - 1;
		int sum = 0;
		while (j + 1 < n && cnt[j + 1]){
			++j;
			sum += cnt[j];
		}
		res += (j - i + 1);
		if (sum > j - i + 1 && (!right || dist > 1)){
			--sum;
			++res;
		}
		right = false;
		if (sum > j - i + 1){
			right = true;
			++res;
		}
		i = j;
		dist = 0;
	}
	return res;
}

void solve(){
	int n;
	rd(n);
	int arr[n];
	cnt.resize(n+1);
	FOR(i,n)rd(arr[i]),cnt[arr[i]-1]++;
	sort(arr,arr+n);
	int gre=0,sma=go(0,0,arr,n);
	// memset(dp,-1,sizeof(dp));
	pp(sma,solvemax());
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
