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
// bool go(int n,bool flag){
	// if(n==1)return flag;
	// if(n%2==0)return flag;
	// int temp=false;
	// for(int i=0;i<32;i++){
		// if((n>>i)&1){
			// temp|=go(n-pow(2,i),!flag);
		// }
	// }
	// if(flag){
		// if(temp)return false;
		// return true;
	// }
	// else{
		// if(temp)return true;
		// return false;
	// }
// }
void solve(){
	int n;
	rd(n);
	if(n==3)pp("B");
	else pp("A");
	/*
	int dp[100000];
	dp[1]=1;
	dp[2]=1;
	// dp[3]=0;
	rep(i,3,1001)
	{
		if(i%2==0){
			dp[i]=1;
			pp(i,"A");
			continue;
		}
		if(dp[i-1]==0)dp[i]=1;
		else{
			bool pos=false;
			for(int j=2;;j+=2){
				if(i-j<1)break;
				if(dp[i-j]==0){
					dp[i]=1;
					pos=true;
					break;
				}
			}
			if(pos==false)dp[i]=0;
		}
		if(dp[i])pp(i,"A");
		else pp(i,"B");
	}
	*/
	return;	
}


int32_t main() {
    fint{
    	fast;
    	solve();
    }
    return 0;
}
