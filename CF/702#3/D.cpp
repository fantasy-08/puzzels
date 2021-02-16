
// Problem : D. Permutation Transformation
// Contest : Codeforces - Codeforces Round #702 (Div. 3)
// URL : https://codeforces.com/contest/1490/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
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
int dp[105][105][105];
map<int,int>X;
void go(vint &arr,int l,int r,int& d)
{
	if(l>r)return ;
	if(l==r)
	{
		X[l]=d;
		return ;
	}
	// Error(l,r);
	// if(dp[l][r]!=-1)
		// return dp[l][r];
	int par=arr[l],ind=l;
	for(int i=l+1;i<=r;i++){
		if(arr[i]>par){
			par=arr[i],ind=i;
		}
	}
	X[ind]=d;
	int k=d;
	d++;
	// Error(ind,d);
	go(arr,l,ind-1,d);
	k++;
	go(arr,ind+1,r,k);
	// return ans;
}

void solve(){
	input(arr,n);
	X.clear();
	int t=0;
	go(arr,0,n-1,t);
	rep(i,0,n)
	{
		cout<<X[i]<<" ";
	}
	pp("");
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
